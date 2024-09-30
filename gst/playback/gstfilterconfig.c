#include <stdio.h>
#include <stdlib.h>

#include <glib.h>
#include "gstfilterconfig.h"

char *vfilter_name;
void gst_filter_get_vfilter_config_file ()
{
  static const gchar *config_name = "gstpbfilter.conf";
  gchar filename[256];
  gchar str[256];
  FILE *fp;

  snprintf (filename, sizeof (filename), "/etc/%s", config_name);

  fp = fopen (filename, "r");
  if (!fp) {
    goto skip_config;
  }

  while (fgets (str, sizeof (str), fp) != NULL) {
    if (strncmp (str, FILTER_CONF_VFILTER_NAME, strlen (FILTER_CONF_VFILTER_NAME)) == 0) {
      str[strlen (str) - 1] = '\0';
      vfilter_name = g_strdup (str + strlen (FILTER_CONF_VFILTER_NAME));
      goto exit;
    }
  };
skip_config:
  vfilter_name = COLORSPACE;
exit:
  fclose(fp);
}
