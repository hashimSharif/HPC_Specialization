FILE(REMOVE_RECURSE
  "CMakeFiles/libomp-test-instr"
  "test-instr/.success"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/libomp-test-instr.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
