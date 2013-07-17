<?php
/**
 * @file
 * camplus_user_fields.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function camplus_user_fields_user_default_permissions() {
  $permissions = array();

  // Exported permission: create field_first_name.
  $permissions['create field_first_name'] = array(
    'name' => 'create field_first_name',
    'roles' => array(
      'parent' => 'parent',
      'principal' => 'principal',
      'school admin' => 'school admin',
      'staff' => 'staff',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_last_name.
  $permissions['create field_last_name'] = array(
    'name' => 'create field_last_name',
    'roles' => array(
      'parent' => 'parent',
      'principal' => 'principal',
      'school admin' => 'school admin',
      'staff' => 'staff',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_children.
  $permissions['edit field_children'] = array(
    'name' => 'edit field_children',
    'roles' => array(
      'school admin' => 'school admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_classid.
  $permissions['edit field_classid'] = array(
    'name' => 'edit field_classid',
    'roles' => array(
      'school admin' => 'school admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_first_name.
  $permissions['edit field_first_name'] = array(
    'name' => 'edit field_first_name',
    'roles' => array(
      'school admin' => 'school admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_last_name.
  $permissions['edit field_last_name'] = array(
    'name' => 'edit field_last_name',
    'roles' => array(
      'school admin' => 'school admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_first_name.
  $permissions['edit own field_first_name'] = array(
    'name' => 'edit own field_first_name',
    'roles' => array(
      'parent' => 'parent',
      'principal' => 'principal',
      'school admin' => 'school admin',
      'staff' => 'staff',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_last_name.
  $permissions['edit own field_last_name'] = array(
    'name' => 'edit own field_last_name',
    'roles' => array(
      'parent' => 'parent',
      'principal' => 'principal',
      'school admin' => 'school admin',
      'staff' => 'staff',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_children.
  $permissions['view field_children'] = array(
    'name' => 'view field_children',
    'roles' => array(
      'principal' => 'principal',
      'school admin' => 'school admin',
      'staff' => 'staff',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_classid.
  $permissions['view field_classid'] = array(
    'name' => 'view field_classid',
    'roles' => array(
      'principal' => 'principal',
      'school admin' => 'school admin',
      'staff' => 'staff',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_first_name.
  $permissions['view field_first_name'] = array(
    'name' => 'view field_first_name',
    'roles' => array(
      'parent' => 'parent',
      'principal' => 'principal',
      'school admin' => 'school admin',
      'staff' => 'staff',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_last_name.
  $permissions['view field_last_name'] = array(
    'name' => 'view field_last_name',
    'roles' => array(
      'parent' => 'parent',
      'principal' => 'principal',
      'school admin' => 'school admin',
      'staff' => 'staff',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_children.
  $permissions['view own field_children'] = array(
    'name' => 'view own field_children',
    'roles' => array(
      'parent' => 'parent',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_classid.
  $permissions['view own field_classid'] = array(
    'name' => 'view own field_classid',
    'roles' => array(
      'student' => 'student',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_first_name.
  $permissions['view own field_first_name'] = array(
    'name' => 'view own field_first_name',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_last_name.
  $permissions['view own field_last_name'] = array(
    'name' => 'view own field_last_name',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
