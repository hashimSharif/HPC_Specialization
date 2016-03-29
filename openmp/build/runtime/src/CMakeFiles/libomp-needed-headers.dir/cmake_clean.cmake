FILE(REMOVE_RECURSE
  "CMakeFiles/libomp-needed-headers"
  "kmp_i18n_id.inc"
  "kmp_i18n_default.inc"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/libomp-needed-headers.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
