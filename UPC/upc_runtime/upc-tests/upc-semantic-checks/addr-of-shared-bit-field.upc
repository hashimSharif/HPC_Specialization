/* Invalid & operation applied to a UPC shared bit field.  */

shared struct 
  {
    int a;
    int b : 8;
    int c : 24;
  } x;

shared int *pts;

int main (void)
{
  pts = &x.b;
  return 0;
}
