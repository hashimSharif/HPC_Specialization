
enum tree_code { BLAH };
union tree_node;
typedef union tree_node *tree;
extern tree chainon (tree a, tree b) { return a; }
extern tree build_tree_list (tree a, tree b) { return a; }
typedef union {long itype; tree ttype; enum tree_code code;
 char *filename; int lineno; int ends_in_label; } YYSTYPE;

int main() {
  register int yyn = 374;
  YYSTYPE yyvsa[200];
  register YYSTYPE *yyvsp = &yyvsa[10];
  YYSTYPE yyval;

  switch (yyn) {
case 374:
{ 
yyval.ttype = chainon (yyvsp[-2].ttype, build_tree_list ((tree) ((void *)0), yyvsp[0].ttype)); ;
    break;}
}

  return 0;
}
