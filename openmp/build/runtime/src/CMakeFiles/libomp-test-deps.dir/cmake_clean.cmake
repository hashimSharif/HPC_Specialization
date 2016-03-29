FILE(REMOVE_RECURSE
  "CMakeFiles/libomp-test-deps"
  "test-deps/.success"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/libomp-test-deps.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
