/*
 Reproducer for bug3202 contributed by Bo Zhang <zhang416 at indiana.edu>
 Original was attached to upc-users list message:
    https://hpcrdm.lbl.gov/pipermail/upc-users/2013-December/001777.html
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <upc_relaxed.h>

#define PTERMS    9
#define NLAMBS    9
#define PGSZ      100
#define PGSZ2     200
#define NEXPTOT   38
#define NEXPTOTP  57
#define NEXPTOTP2 114
#define NEXPMAX   58

typedef struct Box {
  int level, boxid, parent, child[8], nchild, idx, idy, idz, npts, addr; 
} Box; 

shared Box * sboxes; 

shared [PGSZ2] double *mpole, *local; 
shared [NEXPTOTP2] double *expu, *expd, *expn, *exps, *expe, *expw; 

int *numphys, *numfour;
double *whts, *rlams, *rdplus, *rdminus, *rdsq3, *rdmsq3, *dc, *ytopc,
  *ytopcs, *ytopcsinv, *rlsc, *zs, *scale, *xs, *ys, *fexpe, *fexpo, *fexpback; 

void S2M(int sboxid); 
void M2M(int pboxid);
void M2E(int sboxid);
void M2EPhase1(const double *multipole, double *mexpu, double *mexpd);
void M2EPhase2(const double *mexpf, shared [NEXPTOTP2] double *mexpphys); 
void E2LPhase1(const double *mexpphys, double *mexpf);
void E2LPhase2(int iexpu, const double *mexpu, int iexpd, 
			      const double *mexpd, double *local);

void frmini(void); 
void rotgen(void);
void bnlcft(double *c, int p);
void fstrtn(int p, double *d, const double *sqc, double theta);
void vwts(void);
void rlscini(void);
void numthetafour(void);
void lgndr(int nmax, double x, double *y);
void mkfexp(void); 
void mkexps(void);
void rotz2y(const double *multipole, const double *rd, double *mrotate);
void rotz2x(const double *multipole, const double *rd, double *mrotate);
void roty2z(const double *multipole, const double *rd, double *mrotate);


void MakeUList(const int *list, int nlist, const int *xoff, const int *yoff, 
	       double *mexpo, shared [NEXPTOTP2] double *expo);
void MakeDList(const int *list, int nlist, const int *xoff, const int *yoff, 
	       double *mexpo, shared [NEXPTOTP2] double *expo);


int main(int argc, char **argv)
{
  return 0; 
}

#ifdef workaround
void MakeUList(const int *list, int nlist, const int *xoff, const int *yoff, 
	       double *mexpo, shared [NEXPTOTP2] double *expo)
{ }

void MakeDList(const int *list, int nlist, const int *xoff, const int *yoff, 
	       double *mexpo, shared [NEXPTOTP2] double *expo)
{ }
#endif

void S2M(int sboxid)
{
  shared [PGSZ2] double *multipole = &mpole[PGSZ2*sboxid]; 

  shared const Box *sbox = &sboxes[sboxid]; 
  int addr = sbox->addr;
  int level = sbox->level; 
  int nsources = sbox->npts; 
  double myscale = scale[level]; 
  double h = 0; 
  int ix = sbox->idx, iy = sbox->idy, iz = sbox->idz; 
  double x0y0z0[3] = {0,0,0};
  const double precision = 1.0e-14; 
  double powers[PTERMS + 1], p[PGSZ], ephi[2*(PTERMS + 1)]; 

  for (int i = 0; i < nsources; i++) {
    double rx = 0, ry = 0, rz = 0, charge = 0; 
    double proj = rx*rx + ry*ry; 
    double rr = proj + rz*rz; 
    proj = sqrt(proj); 
    double d = sqrt(rr); 
    double ctheta = (d <= precision ? 1.0 : rz/d); 
    if (proj <= precision*d) {
      ephi[0] = 1.0; 
      ephi[1] = 0.0; 
    } else {
      ephi[0] = rx/proj; 
      ephi[1] = ry/proj;
    }

    d *= myscale; 
    powers[0] = 1.0; 
    for (int ell = 1; ell <= PTERMS; ell++) {
      powers[ell] = powers[ell - 1]*d; 
      double a = ephi[2*ell - 2], b = ephi[2*ell - 1], c = ephi[0], d = ephi[1]; 
      ephi[2*ell] = a*c - b*d; 
      ephi[2*ell + 1] = b*c + a*d; 
    }

    multipole[0] += charge; 

    lgndr(PTERMS, ctheta, p); 

    for (int ell = 1; ell <= PTERMS; ell++) {
      double cp = charge*powers[ell]*p[ell]; 
      multipole[2*ell] += cp; 
    }

    for (int m = 1; m <= PTERMS; m++) {
      int offset = m*(PTERMS + 1); 
      for (int ell = m; ell <= PTERMS; ell++) {
	int index = ell + offset; 
	double cp = charge*powers[ell]*ytopc[index]*p[index]; 
	double a = ephi[2*m - 2], b = ephi[2*m - 1]; 
	multipole[2*index] += cp*a; 
	multipole[2*index + 1] -= cp*b; 
      }
    }
  }  
}

void M2M(int pboxid)
{
  double arg = sqrt(2)/2.0; 
  double var[10] = {1, 0, -1, 1, 1, 1, 1, -1, -1, -1}; 
  shared const Box *pbox = &sboxes[pboxid]; 
  shared [PGSZ2] double *pmultipole = &mpole[PGSZ2*pboxid]; 
  int lev = pbox->level; 
  double sc1 = scale[lev + 1], sc2 = scale[lev]; 

  double powers[PTERMS + 3], mpolen[PGSZ2], marray[PGSZ2], ephi[2*PTERMS + 6]; 

  for (int i = 0; i < 8; i++) {
    int child = pbox->child[i]; 
    if (child) {
      shared const Box *cbox = &sboxes[child]; 
      int ifl = i; 
      double *rd = (i < 4 ? rdsq3 : rdmsq3); 
      shared [PGSZ2] double *cmultipole = &mpole[PGSZ2*child]; 

      ephi[0] = 1.0; 
      ephi[1] = 0.0; 
      ephi[2] = arg*var[2*ifl]; 
      ephi[3] = arg*var[2*ifl + 1]; 
      double dd = -sqrt(3)/2.0; 
      powers[0] = 1.0; 

      for (int ell = 1; ell <= PTERMS + 1; ell++) {
	powers[ell ] = powers[ell - 1]*dd; 
	double a = ephi[2*ell], b = ephi[2*ell + 1], c = ephi[2], d = ephi[3]; 
	ephi[2*ell + 2] = a*c - b*d; 
	ephi[2*ell + 3] = b*c + a*d; 
      }

      for (int m = 0; m <= PTERMS; m++) {
	int offset = m*(PTERMS + 1); 
	for (int ell = m; ell <= PTERMS; ell++) {
	  int index = ell + offset; 
	  double a = ephi[2*m], b = ephi[2*m + 1], c = cmultipole[2*index], d = cmultipole[2*index + 1]; 
	  mpolen[2*index] = a*c + b*d; 
	  mpolen[2*index + 1] = a*d - b*c; 
	}
      }

      for (int m = 0; m <= PTERMS; m++) {
	int offset = m*(PTERMS + 1); 
	int offset1 = (PTERMS + m)*PGSZ; 
	int offset2 = (PTERMS - m)*PGSZ; 
	for (int ell = m; ell <= PTERMS; ell++) {
	  int index = offset + ell; 
	  marray[2*index] = mpolen[2*ell]*rd[ell + offset1]; 
	  marray[2*index + 1] = mpolen[2*ell + 1]*rd[ell + offset1]; 
	  for (int mp = 1; mp <= ell; mp++) {
	    int index1 = ell + mp*(PTERMS + 1); 
	    double a = mpolen[2*index1], b = mpolen[2*index1 + 1], 
	      c = rd[index1 + offset1], d = rd[index1 + offset2]; 
	    marray[2*index] = a*(c + d); 
	    marray[2*index + 1] = b*(c - d); 
	  }
	}
      }

      for (int k = 0; k <= PTERMS; k++) {
	int offset = k*(PTERMS + 1); 
	for (int j = k; j <= PTERMS; j++) {
	  int index = offset + j; 
	  mpolen[2*index] = marray[2*index]; 
	  mpolen[2*index + 1] = marray[2*index + 1]; 
	  for (int ell = 1; ell <= j - k; ell++) {
	    int index2 = j - k + ell*(2*PTERMS + 1); 
	    int index3 = j + k + ell*(2*PTERMS + 1); 
	    double a = marray[2*(index - ell)], b = marray[2*(index - ell) + 1], 
	      c = powers[ell]*dc[index2]*dc[index3]; 
	    mpolen[2*index] += a*c; 
	    mpolen[2*index + 1] += b*c;
	  }
	}
      }

      for (int m = 0; m <= PTERMS; m += 2) {
	int offset = m*(PTERMS + 1); 
	int offset1 = (PTERMS + m)*PGSZ; 
	int offset2 = (PTERMS - m)*PGSZ; 
	for (int ell = m; ell <= PTERMS; ell++) {
	  int index = ell + offset; 
	  marray[2*index] = mpolen[2*ell]*rd[ell + offset1]; 
	  marray[2*index + 1] = mpolen[2*ell + 1]*rd[ell + offset1]; 
	  for (int mp = 1; mp <= ell; mp += 2) {
	    int index1 = ell + mp*(PTERMS + 1); 
	    double a = mpolen[2*index1], b = mpolen[2*index1 + 1], 
	      c = rd[index1 + offset1], d = rd[index1 + offset2]; 
	    marray[2*index] -= a*(c + d); 
	    marray[2*index + 1] -= b*(c - d); 
	  }

	  for (int mp = 2; mp <= ell; mp += 2) {
	    int index1 = ell + mp*(PTERMS + 1); 
	    double a = mpolen[2*index1], b = mpolen[2*index + 1], 
	      c = rd[index1 + offset1], d = rd[index1 + offset2]; 
	    marray[2*index] += a*(c + d); 
	    marray[2*index + 1] += b*(c - d); 
	  }
	}
      }

      for (int m = 1; m <= PTERMS; m += 2) {
	int offset = m*(PTERMS + 1); 
	int offset1 = (PTERMS + m)*PGSZ;
	int offset2 = (PTERMS - m)*PGSZ; 
	for (int ell = m; ell <= PTERMS; ell++) {
	  int index = ell + offset; 
	  marray[2*index] -= mpolen[2*ell]*rd[ell + offset1]; 
	  marray[2*index + 1] -= mpolen[2*ell + 1]*rd[ell + offset1]; 
	  for (int mp = 1; mp <= ell; mp += 2) {
	    int index1 = ell + mp*(PTERMS + 1); 
	    double a = mpolen[2*index1], b = mpolen[2*index1 + 1], 
	      c = rd[index1 + offset1], d = rd[index1 + offset2]; 
	    marray[2*index] += a*(c + d); 
	    marray[2*index + 1] += b*(c - d); 
	  }

	  for (int mp = 2; mp <= ell; mp += 2) {
	    int index1 = ell + mp*(PTERMS + 1); 
	    double a = mpolen[2*index1], b = mpolen[2*index1 + 1], 
	      c = rd[index1 + offset1], d = rd[index1 + offset2]; 
	    marray[2*index] -= a*(c + d); 
	    marray[2*index + 1] -= b*(c - d); 
	  }
	}
      }

      powers[0] = 1.0; 
      dd = sc2/sc1; 
      for (int ell = 1; ell <= PTERMS + 1; ell++) 
	powers[ell] = powers[ell - 1]*dd; 

      for (int m = 0; m <= PTERMS; m++) {
	int offset = m*(PTERMS + 1); 
	for (int ell = m; ell <= PTERMS; ell++) {
	  int index = ell + offset; 
	  double a = ephi[2*m], b = ephi[2*m + 1], c = marray[2*index], d = marray[2*index + 1]; 
	  mpolen[2*index] = (a*c - b*d)*powers[ell]; 
	  mpolen[2*index + 1] = (b*c + a*d)*powers[ell]; 
	}
      }

      for (int m = 0; m < PGSZ2; m++) 
	pmultipole[m] += mpolen[m]; 
    }
  }      
}

void M2E(int sboxid)
{
  double mexpf1[2*NEXPMAX], mexpf2[2*NEXPMAX], mw[PGSZ2], work[PGSZ2]; 

  upc_memget(work, &mpole[PGSZ2*sboxid], PGSZ2*sizeof(double)); 

  M2EPhase1(work, mexpf1, mexpf2); 
  M2EPhase2(mexpf1, &expu[NEXPTOTP2*sboxid]); 
  M2EPhase2(mexpf2, &expd[NEXPTOTP2*sboxid]); 

  rotz2y(work, rdminus, mw); 
  M2EPhase1(mw, mexpf1, mexpf2); 
  M2EPhase2(mexpf1, &expn[NEXPTOTP2*sboxid]); 
  M2EPhase2(mexpf2, &exps[NEXPTOTP2*sboxid]); 

  rotz2x(work, rdplus, mw); 
  M2EPhase1(mw, mexpf1, mexpf2); 
  M2EPhase2(mexpf1, &expe[NEXPTOTP2*sboxid]);
  M2EPhase2(mexpf2, &expw[NEXPTOTP2*sboxid]); 
}

void M2EPhase1(const double *multipole, double *mexpu, double *mexpd)
{
  int ntot = 0; 
  for (int nell = 0; nell < NLAMBS; nell++) {
    double sgn = -1.0; 
    double a = 1.0, b = 0.0; 
    for (int mth = 0; mth <= numfour[nell] - 1; mth++) {
      int ncurrent = ntot + mth; 
      double ztmp1 = 0.0, ztmp2 = 0.0, ztmp3 = 0.0, ztmp4 = 0.0; 
      sgn = -sgn; 
      int offset = mth*(PTERMS + 1); 
      int offset1 = offset + nell*PGSZ; 
      for (int nm = mth; nm <= PTERMS; nm += 2) {
	ztmp1 += rlsc[nm + offset1]*multipole[2*(nm + offset)]; 
	ztmp2 += rlsc[nm + offset1]*multipole[2*(nm + offset) + 1];
      }
      
      for (int nm = mth + 1; nm <= PTERMS; nm += 2) {
	ztmp3 += rlsc[nm + offset1]*multipole[2*(nm + offset)]; 
	ztmp4 += rlsc[nm + offset1]*multipole[2*(nm + offset) + 1]; 
      }

      int c = ztmp1 + ztmp3, d = ztmp2 + ztmp4, e = ztmp1 - ztmp3, f = ztmp2 - ztmp4; 

      mexpu[2*ncurrent] = a*c - b*d; 
      mexpu[2*ncurrent + 1] = b*c + a*d; 
      mexpd[2*ncurrent] = sgn*(a*e - b*f); 
      mexpd[2*ncurrent + 1] = sgn*(b*e + a*f); 

      double tmp = a; 
      a = -b; 
      b = tmp; 
    }
    ntot += numfour[nell]; 
  }            
}

void M2EPhase2(const double *mexpf, shared [NEXPTOTP2] double *mexpphys)
{
  int nftot = 0, nptot = 0, nexte = 0, nexto = 0; 
  for (int i = 0; i < NLAMBS; i++) {
    for (int ival = 0; ival < numphys[i]/2; ival++) {
      mexpphys[2*(nptot + ival)] = mexpf[2*nftot]; 
      mexpphys[2*(nptot + ival) + 1] = mexpf[2*nftot + 1]; 
      for (int nm = 1; nm < numfour[i]; nm += 2) {
	double a = fexpe[2*nexte], b = fexpe[2*nexte + 1], 
	  c = mexpf[2*(nftot + nm)], d = mexpf[2*(nftot + nm) + 1]; 
	double rt1 = b*c; 
	double rt2 = a*d;
	double rtmp = 2*(rt1 + rt2); 
	nexte++; 
	mexpphys[2*(nptot + ival) + 1] += rtmp; 
      }

      for (int nm = 2; nm < numfour[i]; nm += 2) {
	double a = fexpo[2*nexto], b = fexpo[2*nexto + 1], 
	  c = mexpf[2*(nftot + nm)], d = mexpf[2*(nftot + nm) + 1]; 
	double rt1 = a*c; 
	double rt2 = b*d; 
	double rtmp = 2*(rt1 - rt2); 
	nexto++; 
	mexpphys[2*(nptot + ival)] += rtmp; 
      }
    }

    nftot += numfour[i]; 
    nptot += numphys[i]/2;
  }      
}

void E2LPhase1(const double *mexpphys, double *mexpf)
{
  int nftot = 0, nptot = 0, next = 0; 
  for (int i = 0; i < NLAMBS; i++) {
    int nalpha = numphys[i]; 
    int nalpha2 = nalpha/2;
    mexpf[2*nftot] = 0; 
    mexpf[2*nftot + 1] = 0; 
    for (int ival = 0; ival < nalpha2; ival++) {
      mexpf[2*nftot] += 2.0*mexpphys[2*(nptot + ival)]; 
    }
    mexpf[2*nftot] /= nalpha;
    mexpf[2*nftot + 1] /= nalpha;

    for (int nm = 2; nm < numfour[i]; nm += 2) {
      mexpf[2*(nftot + nm)] = 0; 
      mexpf[2*(nftot + nm) + 1] = 0; 
      for (int ival = 0; ival < nalpha2; ival++) {
	double rtmp = 2*mexpphys[2*(nptot + ival)]; 
	mexpf[2*(nftot + nm)] += fexpback[2*next]*rtmp; 
	mexpf[2*(nftot + nm) + 1] += fexpback[2*next + 1]*rtmp;
	next++;
      }
      mexpf[2*(nftot + nm)] /= nalpha;
      mexpf[2*(nftot + nm) + 1] /= nalpha;
    }

    for (int nm = 1; nm < numfour[i]; nm += 2) {
      mexpf[2*(nftot + nm)] = 0;
      mexpf[2*(nftot + nm) + 1] = 0;
      for (int ival = 0; ival < nalpha2; ival++) {
	double ztmp = 2*mexpphys[2*(nptot + ival) + 1]; 
	mexpf[2*(nftot + nm)] -= fexpback[2*next + 1]*ztmp; 
	mexpf[2*(nftot + nm) + 1] += fexpback[2*next]*ztmp; 
	next++;
      }
      mexpf[2*(nftot + nm)] /= nalpha;
      mexpf[2*(nftot + nm) + 1] /= nalpha;
    }

    nftot += numfour[i];
    nptot += numphys[i]/2;
  }
}

void E2LPhase2(int iexpu, const double *mexpu, int iexpd, 
			      const double *mexpd, double *local)
{
  double rlampow[PTERMS + 1], zeye[2*(PTERMS + 1)], 
    mexpplus[2*NEXPTOT], mexpminus[2*NEXPTOT]; 

  zeye[0] = 1.0; 
  zeye[1] = 0.0; 
  for (int i = 1; i <= PTERMS; i++) {
    zeye[2*i] = - zeye[2*i - 1]; 
    zeye[2*i + 1] = zeye[2*i - 2]; 
  }

  for (int i = 0; i < PGSZ2; i++)
    local[i] = 0;

  for (int i = 0; i < NEXPTOT; i++) {
    if (iexpu <= 0) {
      mexpplus[2*i] = mexpd[2*i]; 
      mexpplus[2*i + 1] = mexpd[2*i + 1]; 
      mexpminus[2*i] = mexpd[2*i]; 
      mexpminus[2*i + 1] = mexpd[2*i + 1]; 
    } else if (iexpd <= 0) {
      mexpplus[2*i] = mexpu[2*i];
      mexpplus[2*i + 1] = mexpu[2*i + 1]; 
      mexpminus[2*i] = -mexpu[2*i]; 
      mexpminus[2*i + 1] = -mexpu[2*i + 1]; 
    } else {
      mexpplus[2*i] = mexpd[2*i] + mexpu[2*i]; 
      mexpplus[2*i + 1] = mexpd[2*i + 1] + mexpu[2*i + 1]; 
      mexpminus[2*i] = mexpd[2*i] - mexpu[2*i]; 
      mexpminus[2*i + 1] = mexpd[2*i + 1] - mexpu[2*i + 1]; 
    }
  }

  int ntot = 0; 
  for (int nell = 0; nell < NLAMBS; nell++) {
    rlampow[0] = whts[nell]; 
    double rmul = rlams[nell];
    for (int j = 1; j <= PTERMS; j++)
      rlampow[j] = rlampow[j - 1]*rmul;
    
    int mmax = numfour[nell] - 1;
    for (int mth = 0; mth <= mmax; mth += 2) {
      int offset = mth*(PTERMS + 1);
      for (int nm = mth; nm <= PTERMS; nm += 2) {
	int index = offset + nm;
	int ncurrent = ntot + mth;
	rmul = rlampow[nm]; 
	local[index*2] += rmul*mexpplus[2*ncurrent]; 
	local[index*2] += rmul*mexpplus[2*ncurrent + 1];
      }

      for (int nm = mth + 1; nm <= PTERMS; nm += 2) {
	int index = offset + nm;
	int ncurrent = ntot + mth; 
	rmul = rlampow[nm]; 
	local[2*index] += rmul*mexpminus[2*ncurrent]; 
	local[2*index + 1] += rmul*mexpminus[2*ncurrent + 1];
      }
    }

    for (int mth = 1; mth <= mmax; mth += 2) {
      int offset = mth*(PTERMS + 1);
      for (int nm = mth + 1; nm <= PTERMS; nm += 2) {
	int index = nm + offset; 
	int ncurrent = ntot + mth;
	rmul = rlampow[nm]; 
	local[2*index] += rmul*mexpplus[2*ncurrent]; 
	local[2*index + 1] += rmul*mexpplus[2*ncurrent + 1]; 
      }

      for (int nm = mth; nm <= PTERMS; nm += 2) {
	int index = nm + offset; 
	int ncurrent = ntot + mth;
	rmul = rlampow[nm]; 
	local[2*index] += rmul*mexpminus[ncurrent*2]; 
	local[2*index + 1] += rmul*mexpminus[ncurrent*2 + 1];
      }
    }
    
    ntot += numfour[nell];
  }

  
  for (int mth = 0; mth <= PTERMS; mth++) {
    int offset = mth*(PTERMS + 1);
    for (int nm = mth; nm <= PTERMS; nm++) {
      int index = nm + offset; 
      double a = local[2*index], b = local[2*index + 1], c = zeye[2*mth], 
	d = zeye[2*mth + 1], e = ytopcs[index]; 
	local[2*index] = e*(a*c - b*d); 
	local[2*index + 1] = e*(b*c + a*d);
    }
  }
}


void frmini(void)
{
  double d = 1.0, factorial[2*PTERMS + 1] = {0}; 

  factorial[0] = d;
  for (int ell = 1; ell <= 2*PTERMS; ell++) {
    d *= sqrt(ell);
    factorial[ell] = d;
  }

  ytopcs[0] = 1.0;
  ytopcsinv[0] = 1.0;
  for (int m = 0; m <= PTERMS; m++) {
    int offset = m*(PTERMS + 1);
    for (int ell = m; ell <= PTERMS; ell++) {
      ytopc[ell + offset] = factorial[ell - m]/factorial[ell + m];
      ytopcsinv[ell + offset] = factorial[ell - m]*factorial[ell + m];
      ytopcs[ell + offset] = 1.0/ytopcsinv[ell + offset];
    }
  }
}

void rotgen(void)
{
  bnlcft(dc, 2*PTERMS); 
  double theta = acos(0);
  fstrtn(PTERMS, rdplus, dc, theta);
  theta = -theta;
  fstrtn(PTERMS, rdminus, dc, theta);
  theta = acos(sqrt(3)/3);
  fstrtn(PTERMS, rdsq3, dc, theta);
  theta = acos(-sqrt(3)/3);
  fstrtn(PTERMS, rdmsq3, dc, theta);
}

void bnlcft(double *c, int p)
{
  for (int n = 0; n <= p; n++)
    c[n] = 1.0;

  for (int m = 1; m <= p; m++) {
    int offset = m*(p + 1);
    int offset1 = offset - p - 1;
    c[m + offset] = 1.0;
    for (int n = m + 1; n <= p; n++)
      c[n + offset] = c[n - 1 + offset] + c[n - 1 + offset1];
  }

  for (int m = 1; m <= p; m++) {
    int offset = m*(p + 1);
    for (int n = m + 1; n <= p; n++) {
      c[n + offset] = sqrt(c[n + offset]);
    }
  }
}

void fstrtn(int p, double *d, const double *sqc, double theta)
{
  const double precision = 1.0e-19;
  const double ww = sqrt(2)/2;
  double ctheta = cos(theta);
  ctheta = (fabs(ctheta) <= precision ? 0.0 : ctheta);
  double stheta = sin(-theta);
  stheta = (fabs(stheta) <= precision ? 0.0 : stheta);
  double hsthta = ww*stheta;
  double cthtap = ww*(1.0 + ctheta);
  double cthtan = -ww*(1.0 - ctheta);

  d[p*PGSZ] = 1.0;
  for (int ij = 1; ij <= p; ij++) {
    for (int im = -ij; im <= -1; im++) {
      int index = ij + (im + p)*PGSZ;
      d[index] = -sqc[ij - im + 2*(1 + 2*p)]*d[ij-1 + (im + 1 + p)*PGSZ];
      if (im > 1 - ij)
	d[index] += sqc[ij + im + 2*(1 + 2*p)]*d[ij - 1 + (im - 1 + p)*PGSZ];
      d[index] *= hsthta;
      
      if (im > -ij)
	d[index] += d[ij - 1 + (im + p)*PGSZ]*ctheta*
	  sqc[ij + im + 2*p + 1]*sqc[ij - im + 2*p + 1];
      d[index] /= ij;
    }
    
    d[ij + p*PGSZ] = d[ij - 1 + p*PGSZ]*ctheta;

    if (ij > 1)
      d[ij + p*PGSZ] += hsthta*sqc[ij + 2*(1 + 2*p)]*
	(d[ij - 1 + (-1 + p)*PGSZ] + d[ij - 1 + (1 + p)*PGSZ])/ij;
    
    for (int im = 1; im <= ij; im++) {
      int index = ij + (im + p)*PGSZ;
      d[index] = -sqc[ij + im + 2*(1 + 2*p)]*d[ij - 1 + (im - 1 + p)*PGSZ];
      if (im < ij-1)
	d[index] += sqc[ij - im + 2*(1 + 2*p)]*d[ij - 1 + (im + 1 + p)*PGSZ];
      d[index] *= hsthta;
      
      if (im < ij)
	d[index] += d[ij- 1 + (im + p)*PGSZ]*ctheta*
	  sqc[ij + im + 2*p + 1]*sqc[ij - im + 2*p + 1];
      d[index] /= ij;
    }

    for (int imp = 1; imp <= ij; imp++) {
      for (int im = -ij; im <= -1; im++) {
	int index1 = ij + imp*(p + 1) + (im + p)*PGSZ;
	int index2 = ij - 1 + (imp - 1)*(p + 1) + (im + p)*PGSZ;
	d[index1] = d[index2 + PGSZ]*cthtan*sqc[ij - im + 2*(2*p + 1)];
	if (im > 1 - ij)
	  d[index1] -= d[index2 - PGSZ]*cthtap*sqc[ij + im + 2*(2*p + 1)];

	if (im > -ij)
	  d[index1] += d[index2]*stheta*sqc[ij + im + 2*p + 1]*
	    sqc[ij - im + 2*p + 1];
	d[index1] *= ww/sqc[ij + imp + 2*(2*p + 1)];
      }

      int index3 = ij + imp*(p + 1) + p*PGSZ;
      int index4 = ij - 1 + (imp - 1)*(p + 1) + p*PGSZ;
      d[index3] = ij*stheta*d[index4];
      if (ij > 1)
	d[index3] -= sqc[ij + 2*(2*p + 1)]*
	  (d[index4 - PGSZ]*cthtap + d[index4 + PGSZ]*cthtan);
      d[index3] *= ww/sqc[ij + imp + 2*(2*p + 1)];
      
      for (int im = 1; im <= ij; im++) {
	int index5 = ij + imp*(p + 1) + (im + p)*PGSZ;
	int index6 = ij - 1 + (imp - 1)*(p + 1) + (im + p)*PGSZ;
	d[index5] = d[index6 - PGSZ]*cthtap*sqc[ij + im + 2*(2*p + 1)];
	if (im < ij - 1)
	  d[index5] -= d[index6 + PGSZ]*cthtan*sqc[ij - im + 2*(2*p + 1)];
	
	if (im < ij)
	  d[index5] += d[index6]*stheta*sqc[ij + im + 2*p + 1]*
	    sqc[ij - im + 2*p + 1];
	d[index5] *= ww/sqc[ij + imp + 2*(2*p + 1)];
      }
    }
  }
}

void vwts(void)
{
 if (NLAMBS == 9) {
    rlams[0] = 0.99273996739714473469540223504736787e-01;
    rlams[1] = 0.47725674637049431137114652301534079e+00;
    rlams[2] = 0.10553366138218296388373573790886439e+01;
    rlams[3] = 0.17675934335400844688024335482623428e+01;
    rlams[4] = 0.25734262935147067530294862081063911e+01;
    rlams[5] = 0.34482433920158257478760788217186928e+01;
    rlams[6] = 0.43768098355472631055818055756390095e+01;
    rlams[7] = 0.53489575720546005399569367000367492e+01;
    rlams[8] = 0.63576578531337464283978988532908261e+01;
    whts[0] = 0.24776441819008371281185532097879332e+00;
    whts[1] = 0.49188566500464336872511239562300034e+00;
    whts[2] = 0.65378749137677805158830324216978624e+00;
    whts[3] = 0.76433038408784093054038066838984378e+00;
    whts[4] = 0.84376180565628111640563702167128213e+00;
    whts[5] = 0.90445883985098263213586733400006779e+00;
    whts[6] = 0.95378613136833456653818075210438110e+00;
    whts[7] = 0.99670261613218547047665651916759089e+00;
    whts[8] = 0.10429422730252668749528766056755558e+01;
  } else if (NLAMBS == 18) {
    rlams[0] = 0.52788527661177607475107009804560221e-01;
    rlams[1] = 0.26949859838931256028615734976483509e+00;
    rlams[2] = 0.63220353174689392083962502510985360e+00;
    rlams[3] = 0.11130756427760852833586113774799742e+01;
    rlams[4] = 0.16893949614021379623807206371566281e+01;
    rlams[5] = 0.23437620046953044905535534780938178e+01;
    rlams[6] = 0.30626998290780611533534738555317745e+01;
    rlams[7] = 0.38356294126529686394633245072327554e+01;
    rlams[8] = 0.46542473432156272750148673367220908e+01;
    rlams[9] = 0.55120938659358147404532246582675725e+01;
    rlams[10] = 0.64042126837727888499784967279992998e+01;
    rlams[11] = 0.73268800190617540124549122992902994e+01;
    rlams[12] = 0.82774009925823861522076185792684555e+01;
    rlams[13] = 0.92539718060248947750778825138695538e+01;
    rlams[14] = 0.10255602723746401139237605093512684e+02;
    rlams[15] = 0.11282088297877740146191172243561596e+02;
    rlams[16] = 0.12334067909676926788620221486780792e+02;
    rlams[17] = 0.13414920240172401477707353478763252e+02;
    whts[0] = 0.13438265914335215112096477696468355e+00;
    whts[1] = 0.29457752727395436487256574764614925e+00;
    whts[2] = 0.42607819361148618897416895379137713e+00;
    whts[3] = 0.53189220776549905878027857397682965e+00;
    whts[4] = 0.61787306245538586857435348065337166e+00;
    whts[5] = 0.68863156078905074508611505734734237e+00;
    whts[6] = 0.74749099381426187260757387775811367e+00;
    whts[7] = 0.79699192718599998208617307682288811e+00;
    whts[8] = 0.83917454386997591964103548889397644e+00;
    whts[9] = 0.87570092283745315508980411323136650e+00;
    whts[10] = 0.90792943590067498593754180546966381e+00;
    whts[11] = 0.93698393742461816291466902839601971e+00;
    whts[12] = 0.96382546688788062194674921556725167e+00;
    whts[13] = 0.98932985769673820186653756536543369e+00;
    whts[14] = 0.10143828459791703888726033255807124e+01;
    whts[15] = 0.10400365437416452252250564924906939e+01;
    whts[16] = 0.10681548926956736522697610780596733e+01;
    whts[17] = 0.11090758097553685690428437737864442e+01;
  }
}

void rlscini(void)
{
  double factorial[2*PTERMS + 1] = {0}, rlampow[PTERMS + 1] = {0}; 

  factorial[0] = 1;
  for (int i = 1; i <= 2*PTERMS; i++)
    factorial[i] = factorial[i-1]*sqrt(i);
 
  for (int nell = 0; nell < NLAMBS; nell++) {
    double rmul = rlams[nell];
    rlampow[0] = 1;
    for (int j = 1; j <= PTERMS; j++)
      rlampow[j] = rlampow[j - 1]*rmul;
    for (int j = 0; j <= PTERMS; j++) {
      for (int k = 0; k <= j; k++) {
	rlsc[j + k*(PTERMS + 1) + nell*PGSZ] =
	  rlampow[j]/factorial[j - k]/factorial[j + k];
      }
    }
  }
}

void numthetafour(void)
{
  if (NLAMBS == 9) {
    numphys[0] = 4;
    numphys[1] = 8;
    numphys[2] = 12;
    numphys[3] = 16;
    numphys[4] = 20;
    numphys[5] = 20;
    numphys[6] = 24;
    numphys[7] = 8;
    numphys[8] = 2;
  } else if (NLAMBS == 18) {
    numphys[0] = 6;
    numphys[1] = 8;
    numphys[2] = 12;
    numphys[3] = 16;
    numphys[4] = 20;
    numphys[5] = 26;
    numphys[6] = 30;
    numphys[7] = 34;
    numphys[8] = 38;
    numphys[9] = 44;
    numphys[10] = 48;
    numphys[11] = 52;
    numphys[12] = 56;
    numphys[13] = 60;
    numphys[14] = 60;
    numphys[15] = 52;
    numphys[16] = 4;
    numphys[17] = 2;
  }
}

void lgndr(int nmax, double x, double *y)
{
  int m, n;
  n = (nmax + 1)*(nmax + 1);
  for (m = 0; m < n; m++)
    y[m] = 0.0;

  double u = -sqrt(1 - x*x);
  y[0] = 1;

  y[1] = x*y[0];
  for (n = 2; n <= nmax; n++)
    y[n] = ((2*n - 1)*x*y[n - 1] - (n - 1)*y[n - 2])/n;

  int offset1 = nmax + 2;
  for (m = 1; m <= nmax - 1; m++) {
    int offset2 = m*offset1;
    y[offset2] = y[offset2 - offset1]*u*(2*m - 1);
    y[offset2 + 1] = y[offset2]*x*(2*m + 1);
    for (n = m + 2; n <= nmax; n++) {
      int offset3 = n + m*(nmax + 1);
      y[offset3] = ((2*n - 1)*x*y[offset3 - 1] - (n + m - 1)*y[offset3 - 2])/(n - m);
    }
  }

  y[nmax + nmax*(nmax + 1)] = y[nmax - 1 + (nmax - 1)*(nmax + 1)]*u*(2*nmax - 1);
}

void mkfexp(void)
{
  double pi = acos(-1); 
  int nexte = 0, nexto = 0; 
  for (int i = 0; i < NLAMBS; i++) {
    int nalpha = numphys[i]; 
    int nalpha2 = nalpha/2; 
    double halpha = 2.0*pi/nalpha; 
    for (int j = 1; j <= nalpha2; j++) {
      double alpha = (j - 1)*halpha; 
      for (int nm = 2; nm <= numfour[i]; nm += 2) {
	fexpe[2*nexte] = cos((nm - 1)*alpha); 
	fexpe[2*nexte + 1] = sin((nm - 1)*alpha); 
	nexte++; 
      }

      for (int nm = 3; nm <= numfour[i]; nm += 2) {
	fexpo[2*nexto] = cos((nm - 1)*alpha); 
	fexpo[2*nexto + 1] = sin((nm - 1)*alpha); 
	nexto++; 
      }
    }
  }

  int next = 0; 
  for (int i = 0; i < NLAMBS; i++) {
    int nalpha = numphys[i]; 
    int nalpha2 = nalpha/2; 
    double halpha = 2.0*pi/nalpha; 
    for (int nm = 3; nm <= numfour[i]; nm += 2) {
      for (int j = 1; j <= nalpha2; j++) {
	double alpha = (j - 1)*halpha; 
	fexpback[2*next] = cos((nm - 1)*alpha); 
	fexpback[2*next + 1] = -sin((nm - 1)*alpha); 
	next++; 
      }
    }

    for (int nm = 2; nm <= numfour[i]; nm += 2) {
      for (int j = 1; j <= nalpha2; j++) {
	double alpha = (j - 1)*halpha; 
	fexpback[2*next] = cos((nm - 1)*alpha); 
	fexpback[2*next + 1] = -sin((nm - 1)*alpha);
	next++;
      }
    }
  }
}

void mkexps(void)
{
  double pi = acos(-1); 
  int ntot = 0; 
  for (int nell = 0; nell < NLAMBS; nell++) {
    double hu = 2.0*pi/numphys[nell]; 
    for (int mth = 0; mth < numphys[nell]/2; mth++) {
      double u = mth*hu; 
      int ncurrent = 3*(ntot + mth); 
      zs[ncurrent] = exp(-rlams[nell]); 
      zs[ncurrent + 1] = zs[ncurrent]*zs[ncurrent]; 
      zs[ncurrent + 2] = zs[ncurrent]*zs[ncurrent + 1]; 

      ncurrent *= 2; 
      double temp = cos(u)*rlams[nell]; 
      xs[ncurrent] = cos(temp); 
      xs[ncurrent + 1] = sin(temp); 
      xs[ncurrent + 2] = cos(2*temp); 
      xs[ncurrent + 3] = sin(2*temp); 
      xs[ncurrent + 4] = cos(3*temp); 
      xs[ncurrent + 5] = sin(3*temp); 

      temp = sin(u)*rlams[nell]; 
      ys[ncurrent] = cos(temp); 
      ys[ncurrent + 1] = sin(temp); 
      ys[ncurrent + 2] = cos(2*temp); 
      ys[ncurrent + 3] = sin(2*temp); 
      zs[ncurrent + 4] = cos(3*temp); 
      zs[ncurrent + 5] = sin(3*temp); 
    }
    ntot += numphys[nell]/2; 
  }
}

void rotz2y(const double *multipole, const double *rd, double *mrotate)
{
  double mwork[PGSZ2], ephi[2*PTERMS + 2]; 
  ephi[0] = 1.0; 
  ephi[1] = 0.0; 

  for (int m = 1; m <= PTERMS; m++) {
    double a = ephi[2*m - 2], b = ephi[2*m - 1]; 
    ephi[2*m] = b; 
    ephi[2*m + 1] = -a; 
  }

  for (int m = 0; m <= PTERMS; m++) {
    int offset = m*(PTERMS + 1); 
    for (int ell = m; ell <= PTERMS; ell++) {
      int index = offset + ell; 
      double a = ephi[2*m], b = ephi[2*m + 1], c = multipole[2*index], d = multipole[2*index + 1]; 
      mwork[2*index] = a*c - b*d; 
      mwork[2*index + 1] = b*c + a*d; 
    }
  }

  for (int m = 0; m <= PTERMS; m++) {
    int offset = m*(PTERMS + 1); 
    for (int ell = m; ell <= PTERMS; ell++) {
      int index = ell + offset; 
      double a = mwork[2*ell], b = mwork[2*ell + 1], c = rd[ell + (m + PTERMS)*PGSZ]; 
      mrotate[2*index] = a*c; 
      mrotate[2*index + 1] = b*c; 
      for (int mp = 1; mp <= ell; mp++) {
	int index1 = ell + mp*(PTERMS + 1); 
	double a = mwork[2*index1], b = mwork[2*index1 + 1], 
	  c = rd[ell + mp*(PTERMS + 1) + (m + PTERMS)*PGSZ], 
	  d = rd[ell + mp*(PTERMS + 1) + (PTERMS - m)*PGSZ];
	mrotate[2*index] += a*(c + d); 
	mrotate[2*index + 1] += b*(c - d); 
      }
    }
  }
}

void rotz2x(const double *multipole, const double *rd, double *mrotate)
{
  int offset1 = PTERMS*PGSZ; 
  for (int m = 0; m <= PTERMS; m++) {
    int offset2 = m*(PTERMS + 1); 
    int offset3 = offset1 + m*PGSZ; 
    int offset4 = offset1 - m*PGSZ; 
    for (int ell = m; ell <= PTERMS; ell++) {
      double a = multipole[2*ell], b = multipole[2*ell + 1], c = rd[ell + offset3]; 
      mrotate[2*(ell + offset2)] = a*c;
      mrotate[2*(ell + offset2) + 1] = b*c; 
      for (int mp = 1; mp <= ell; mp++) {
	int offset5 = mp*(PTERMS + 1); 
	double a = multipole[2*(ell + offset5)], b = multipole[2*(ell + offset5) + 1], 
	  c = rd[ell + offset3 + offset5], d = rd[ell + offset4 + offset5]; 
	mrotate[2*(ell + offset2)] += a*(c + d); 
	mrotate[2*(ell + offset2) + 1] += b*(c - d); 
      }
    }
  }
}

void roty2z(const double *multipole, const double *rd, double *mrotate)
{
  double mwork[PGSZ2], ephi[2*(PTERMS + 1)]; 

  ephi[0] = 1.0; 
  ephi[1] = 0.0; 
  for (int m = 1; m <= PTERMS; m++) {
    double a = ephi[2*m - 2], b = ephi[2*m - 1]; 
    ephi[2*m] = -b; 
    ephi[2*m + 1] = a; 
  }

  for (int m = 0; m <= PTERMS; m++) {
    int offset = m*(PTERMS + 1); 
    for (int ell = m; ell <= PTERMS; ell++) {
      int index = ell + offset; 
      double a = multipole[2*ell], b = multipole[2*ell + 1], c = rd[ell + (m + PTERMS)*PGSZ]; 
      mwork[2*index] = a*c; 
      mwork[2*index + 1] = b*c; 
      for (int mp = 1; mp <= ell; mp++) {
	int index1 = ell + mp*(PTERMS + 1); 
	double a = multipole[2*index1], b = multipole[2*index1 + 1], 
	  c = rd[ell + mp*(PTERMS + 1) + (PTERMS + m)*PGSZ], 
	  d = rd[ell + mp*(PTERMS + 1) + (PTERMS - m)*PGSZ];
	mwork[2*index] += a*(c + d); 
	mwork[2*index + 1] += b*(c - d); 
      }
    }
  }

  for (int m = 0; m <= PTERMS; m++) {
    int offset = m*(PTERMS + 1); 
    for (int ell = m; ell <= PTERMS; ell++) {
      int index = ell + offset; 
      double a = ephi[2*m], b = ephi[2*m + 1], c = mwork[2*index], d = mwork[2*index + 1]; 
      mrotate[2*index] = a*c - b*d; 
      mrotate[2*index + 1] = b*c + a*d; 
    }
  }
}

#ifndef workaround
void MakeUList(const int *list, int nlist, const int *xoff, const int *yoff, 
	       double *mexpo, shared [NEXPTOTP2] double *expo)
{ }

void MakeDList(const int *list, int nlist, const int *xoff, const int *yoff, 
	       double *mexpo, shared [NEXPTOTP2] double *expo)
{ }
#endif
