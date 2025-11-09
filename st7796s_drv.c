#include <linux/module.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <drm/drm_crtc.h>
#include <drm/drm_encoder.h>
#include <drm/drm_connector.h>
#include <drm/drm_dp_mst_helper.h>

MODULE_AUTHOR("Roo");
MODULE_DESCRIPTION("Minimal ST7796S DRM/KMS driver stub");
MODULE_LICENSE("GPL and additional rights");

static int st7796s_probe(struct platform_device *pdev)
{
    pr_info("ST7796S KMS driver: Probe called.\n");
    return 0;
}

static int st7796s_remove(struct platform_device *pdev)
{
    pr_info("ST7796S KMS driver: Remove called.\n");
    return 0;
}

static const struct of_device_id st7796s_of_match[] = {
    { .compatible = "st,st7796s", },
    { /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, st7796s_of_match);

static struct platform_driver st7796s_driver = {
    .probe      = st7796s_probe,
    .remove     = st7796s_remove,
    .driver     = {
        .name   = "st7796s-kms",
        .of_match_table = st7796s_of_match,
    },
};

static int __init st7796s_init(void)
{
    pr_info("ST7796S KMS driver loading.\n");
    return platform_driver_register(&st7796s_driver);
}

static void __exit st7796s_exit(void)
{
    pr_info("ST7796S KMS driver unloading.\n");
    platform_driver_unregister(&st7796s_driver);
}

module_init(st7796s_init);
module_exit(st7796s_exit);