include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(Porjeto_Jader_V1_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(Porjeto_Jader_V1_default_default_XC8_FILE_TYPE_assemble)
add_library(Porjeto_Jader_V1_default_default_XC8_assemble OBJECT ${Porjeto_Jader_V1_default_default_XC8_FILE_TYPE_assemble})
    Porjeto_Jader_V1_default_default_XC8_assemble_rule(Porjeto_Jader_V1_default_default_XC8_assemble)
    list(APPEND Porjeto_Jader_V1_default_library_list "$<TARGET_OBJECTS:Porjeto_Jader_V1_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(Porjeto_Jader_V1_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(Porjeto_Jader_V1_default_default_XC8_assemblePreprocess OBJECT ${Porjeto_Jader_V1_default_default_XC8_FILE_TYPE_assemblePreprocess})
    Porjeto_Jader_V1_default_default_XC8_assemblePreprocess_rule(Porjeto_Jader_V1_default_default_XC8_assemblePreprocess)
    list(APPEND Porjeto_Jader_V1_default_library_list "$<TARGET_OBJECTS:Porjeto_Jader_V1_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(Porjeto_Jader_V1_default_default_XC8_FILE_TYPE_compile)
add_library(Porjeto_Jader_V1_default_default_XC8_compile OBJECT ${Porjeto_Jader_V1_default_default_XC8_FILE_TYPE_compile})
    Porjeto_Jader_V1_default_default_XC8_compile_rule(Porjeto_Jader_V1_default_default_XC8_compile)
    list(APPEND Porjeto_Jader_V1_default_library_list "$<TARGET_OBJECTS:Porjeto_Jader_V1_default_default_XC8_compile>")

endif()


# Main target for this project
add_executable(Porjeto_Jader_V1_default_image_a4AV4g_I ${Porjeto_Jader_V1_default_library_list})

set_target_properties(Porjeto_Jader_V1_default_image_a4AV4g_I PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${Porjeto_Jader_V1_default_output_dir}")
target_link_libraries(Porjeto_Jader_V1_default_image_a4AV4g_I PRIVATE ${Porjeto_Jader_V1_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
Porjeto_Jader_V1_default_link_rule( Porjeto_Jader_V1_default_image_a4AV4g_I)


