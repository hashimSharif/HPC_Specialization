/* This file should fail to preprocess due to pragma after UPC code*/
typedef shared void *foobar;
#pragma upc c_code
