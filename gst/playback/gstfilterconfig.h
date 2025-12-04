#ifndef _GST_PLAY_BACK_CONFIG_H_
#define _GST_PLAY_BACK_CONFIG_H_

#define FILTER_CONF_VFILTER_NAME "video-filter="

#define GST_VFILTER_NAME(name) \
    ((g_strcmp0(vfilter_name, "default") == 0) ? (name) : (vfilter_name))

extern gchar *vfilter_name;

void gst_filter_get_vfilter_config_file ();

#endif

