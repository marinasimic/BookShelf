message("-- Linking sqlite3")
add_library(sqlite3 sqlite3.dll)
set_target_properties(sqlite3 PROPERTIES LINKER_LANGUAGE C)