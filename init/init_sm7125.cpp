#include <stdio.h>
#include <stdlib.h>

#include <android-base/logging.h>
#include <android-base/properties.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "property_service.h"
#include "vendor_init.h"

#include "init_sm7125.h"

#define MODEL_NAME_LEN 5
#define BUILD_NAME_LEN 8
#define CODENAME_LEN   9


static void property_override(char const prop[], char const value[]) {
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void property_override_quad(char const system_prop[], char const vendor_prop[],  char const product_prop[], char const odm_prop[], char const value[])
{
    property_override(system_prop, value);
    property_override(vendor_prop, value);
    property_override(product_prop, value);
    property_override(odm_prop, value);
}

void vendor_load_properties()
{
    const std::string bootloader = android::base::GetProperty("ro.bootloader", "");
    const std::string bl_model = bootloader.substr(0, MODEL_NAME_LEN);
    const std::string bl_build = bootloader.substr(MODEL_NAME_LEN);

    std::string model;
    std::string device;
    std::string name;

    model = "SM-" + bl_model;

    for (size_t i = 0; i < VARIANT_MAX; i++) {
        std::string model_ = all_variants[i]->model;
        if (model.compare(model_) == 0) {
            device = all_variants[i]->codename;
            break;
        }
    }

    if (device.size() == 0) {
        LOG(ERROR) << "Could not detect device, forcing a52q";
        device = "a52q";
    }

    name = device + "nsxx";

    LOG(INFO) << "Found bootloader: %s", bootloader.c_str();
    LOG(INFO) << "Setting ro.product.model: %s", model.c_str();
    LOG(INFO) << "Setting ro.product.device: %s", device.c_str();
    LOG(INFO) << "Setting ro.product.name: %s", name.c_str();
    LOG(INFO) << "Setting ro.build.product: %s", device.c_str();

    property_override_quad("ro.product.model", "ro.product.vendor.model", "ro.product.product.model", "ro.product.odm.model", model.c_str());
    property_override_quad("ro.product.device", "ro.product.vendor.device", "ro.product.product.device", "ro.product.odm.device", device.c_str());
    property_override_quad("ro.product.name", "ro.product.vendor.name", "ro.product.product.name", "ro.product.odm.name", name.c_str());
    property_override("ro.build.product", device.c_str());
}
