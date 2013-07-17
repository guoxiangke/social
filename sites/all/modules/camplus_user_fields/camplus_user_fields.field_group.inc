<?php
/**
 * @file
 * camplus_user_fields.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function camplus_user_fields_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_account|user|user|form';
  $field_group->group_name = 'group_account';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_info';
  $field_group->data = array(
    'label' => 'Account Info',
    'weight' => '5',
    'children' => array(
      0 => 'field_first_name',
      1 => 'field_last_name',
      2 => 'account',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Account Info',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_account|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|user|user|form';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User Info',
    'weight' => '0',
    'children' => array(
      0 => 'group_account',
      1 => 'group_interest',
      2 => 'group_profile',
      3 => 'group_setting',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'label' => 'User Info',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_info|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_interest|user|user|form';
  $field_group->group_name = 'group_interest';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_info';
  $field_group->data = array(
    'label' => 'Interest',
    'weight' => '6',
    'children' => array(
      0 => 'field_accomplishment',
      1 => 'field_entertainment',
      2 => 'field_sport',
      3 => 'field_subject',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Interest',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_interest|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile|user|user|form';
  $field_group->group_name = 'group_profile';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_info';
  $field_group->data = array(
    'label' => 'Profile Info',
    'weight' => '4',
    'children' => array(
      0 => 'field_about_me',
      1 => 'field_avatar',
      2 => 'field_birthday',
      3 => 'field_gender',
      4 => 'field_nick_name',
      5 => 'picture',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Profile Info',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_profile|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_setting|user|user|form';
  $field_group->group_name = 'group_setting';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_info';
  $field_group->data = array(
    'label' => 'Setting',
    'weight' => '7',
    'children' => array(
      0 => 'field_children',
      1 => 'field_classid',
      2 => 'privatemsg',
      3 => 'timezone',
      4 => 'overlay_control',
      5 => 'locale',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Setting',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_setting|user|user|form'] = $field_group;

  return $export;
}
