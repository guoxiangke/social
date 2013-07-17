<?php
/**
 * @file
 * camplus_user_fields.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function camplus_user_fields_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'unique';
  $rule->name = 'unique';
  $rule->field_name = 'field_classid';
  $rule->col = 'value';
  $rule->entity_type = 'user';
  $rule->bundle = 'user';
  $rule->validator = 'field_validation_unique_validator';
  $rule->settings = array(
    'data' => 'global',
    'bypass' => 0,
    'roles' => array(
      2 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = 'Class ID must be unique!';
  $export['unique'] = $rule;

  return $export;
}
