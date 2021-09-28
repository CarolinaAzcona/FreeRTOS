# Greengrass demo
afr_demo_module()

afr_set_demo_metadata(ID "GREENGRASS_DISCOVERY_DEMO")
afr_set_demo_metadata(DESCRIPTION "An example on how to discover and connect to AWS Greengrass")
afr_set_demo_metadata(DISPLAY_NAME "AWS Greengrass Discovery")

# Add the CMakeLists.txt file of module to metadata list.
afr_module_cmake_files(${AFR_CURRENT_MODULE}
    ${CMAKE_CURRENT_LIST_DIR}/CMakeLists.txt
)

afr_module_sources(
    ${AFR_CURRENT_MODULE}
    INTERFACE
        "${CMAKE_CURRENT_LIST_DIR}/aws_greengrass_discovery_demo.c"
        # Add the header file added to the target's metadata so that it
        # is available in code downloaded from the FreeRTOS console.
        ${AFR_DEMOS_DIR}/include/aws_iot_metrics.h
)

afr_module_include_dirs(
    ${AFR_CURRENT_MODULE}
    INTERFACE
       "${AFR_DEMOS_DIR}/include"
)

afr_module_dependencies(
    ${AFR_CURRENT_MODULE}
    INTERFACE
        AFR::greengrass
        AFR::core_mqtt_demo_dependencies
)
