<?php
/**
 * @file
 * camplus_user_fields.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function camplus_user_fields_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function camplus_user_fields_views_api() {
  return array("api" => "3.0");
}
