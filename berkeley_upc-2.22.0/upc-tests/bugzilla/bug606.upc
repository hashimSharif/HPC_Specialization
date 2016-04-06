#define Real double
typedef struct AmrOpt_rec {
                                                                                 
              
    int max_step;
    Real stop_time;
    int plot_interval;
    int chkpt_interval;
    int async_advance;
    int verbose;
    int debug;
                                                                                 
              
    int slope_order;
    int use_flatten;
    Real visc_coef;
    Real cfl;
    Real initial_cfl;
                                                                                 
              
                                                                                 
              
                                                                                 
              
    int nzone[2];
    int periodic[2];
    int max_level;
    int max_grid_size;
    Real prob_lo[2];
    Real prob_hi[2];
    int ref_ratio[1];
                                                                                 
              
    char prob_name[128];
    int test_prob;
                                                                                 
              
                                                                                 
              
    Real shock_loc[2];
    Real shock_rad;
    Real mach;
    Real gamma;
                                                                                 
              
    Real den_fact;
    Real blob_loc[2];
    Real blob_rad;
                                                                                 
              
                                                                                 
              
    Real xcorner;
    Real alpha;
                                                                                 
              
                                                                                 
              
    int do_logo;
    Real logo_pos[2];
    Real logo_zlim[2];
    Real char_gap;
    Real char_height;
    Real char_thickness;
    Real char_urad;
    Real char_prad;
} AmrOpt;

AmrOpt amropt;

void f() {
int i = 0;
amropt.ref_ratio[i]  = i;
}
int main() {
f();
return 0;
}
