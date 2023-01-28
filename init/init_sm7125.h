#ifndef INIT_SEC_H
#define INIT_SEC_H

#include <string.h>

enum device_variant {
    VARIANT_A525F = 0,
    VARIANT_A525M,
    VARIANT_A725F,
    VARIANT_A725M,
    VARIANT_MAX
};

typedef struct {
    std::string model;
    std::string codename;
} variant;

static const variant international_models = {
    .model = "SM-A525F",
    .codename = "a52q"
};

static const variant international_models_a72 = {
    .model = "SM-A725F",
    .codename = "a72q"
};

static const variant america_models = {
    .model = "SM-A525M",
    .codename = "a52q"
};

static const variant america_models_a72 = {
    .model = "SM-A725M",
    .codename = "a72q"
};

static const variant *all_variants[VARIANT_MAX] = {
    &international_models,
    &international_models_a72,
    &america_models,
    &america_models_a72
};

#endif // INIT_SEC_H
