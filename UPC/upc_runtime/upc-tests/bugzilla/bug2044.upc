int A[10];

int main()
{
        /*
         * To check that the upc_blocksizeof operator applies only to shared
objects or shared-qualified types
         * the compiler MUST give an ERROR in this case where we used with a
non-shared type
         */

        int var_block_size;
        var_block_size = upc_blocksizeof(A);
}
