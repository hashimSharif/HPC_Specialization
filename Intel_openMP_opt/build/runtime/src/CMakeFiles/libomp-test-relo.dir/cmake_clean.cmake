FILE(REMOVE_RECURSE
  "CMakeFiles/libomp-test-relo"
  "test-relo/.success"
  "test-relo/readelf.log"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/libomp-test-relo.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
