struct X_ctype {
        unsigned X_collate:8;
        unsigned X_upper:8;
        unsigned X_lower:8;
        unsigned X_flags:20;
};
extern struct X_ctype *X_ctypemap;
static int X_tolower(int C) {
        return(C == -1 ? -1 : ((X_ctypemap + 1)[C].X_lower));
}

int main() {
 return 0;
}
