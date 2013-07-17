<?php
/**
 * @file
 * camplus_user_mgt.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function camplus_user_mgt_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer users.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'school admin' => 'school admin',
    ),
    'module' => 'user',
  );

  // Exported permission: assign all roles.
  $permissions['assign all roles'] = array(
    'name' => 'assign all roles',
    'roles' => array(
      'principal' => 'principal',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign parent role.
  $permissions['assign parent role'] = array(
    'name' => 'assign parent role',
    'roles' => array(
      'school admin' => 'school admin',
      'staff' => 'staff',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign school admin role.
  $permissions['assign school admin role'] = array(
    'name' => 'assign school admin role',
    'roles' => array(
      'school admin' => 'school admin',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign staff role.
  $permissions['assign staff role'] = array(
    'name' => 'assign staff role',
    'roles' => array(
      'school admin' => 'school admin',
      'staff' => 'staff',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign student role.
  $permissions['assign student role'] = array(
    'name' => 'assign student role',
    'roles' => array(
      'school admin' => 'school admin',
      'staff' => 'staff',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign teacher role.
  $permissions['assign teacher role'] = array(
    'name' => 'assign teacher role',
    'roles' => array(
      'school admin' => 'school admin',
      'staff' => 'staff',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: change own username.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'principal' => 'principal',
    ),
    'module' => 'user',
  );

  // Exported permission: change privatemsg e-mail notification for indirect messages.
  $permissions['change privatemsg e-mail notification for indirect messages'] = array(
    'name' => 'change privatemsg e-mail notification for indirect messages',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'pm_email_notify',
  );

  // Exported permission: clear import_parents feeds.
  $permissions['clear import_parents feeds'] = array(
    'name' => 'clear import_parents feeds',
    'roles' => array(
      'school admin' => 'school admin',
    ),
    'module' => 'feeds',
  );

  // Exported permission: clear import_staff feeds.
  $permissions['clear import_staff feeds'] = array(
    'name' => 'clear import_staff feeds',
    'roles' => array(
      'school admin' => 'school admin',
    ),
    'module' => 'feeds',
  );

  // Exported permission: clear import_students feeds.
  $permissions['clear import_students feeds'] = array(
    'name' => 'clear import_students feeds',
    'roles' => array(
      'school admin' => 'school admin',
    ),
    'module' => 'feeds',
  );

  // Exported permission: clear import_teachers feeds.
  $permissions['clear import_teachers feeds'] = array(
    'name' => 'clear import_teachers feeds',
    'roles' => array(
      'school admin' => 'school admin',
    ),
    'module' => 'feeds',
  );

  // Exported permission: delete privatemsg.
  $permissions['delete privatemsg'] = array(
    'name' => 'delete privatemsg',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: execute views_bulk_operations_delete_item.
  $permissions['execute views_bulk_operations_delete_item'] = array(
    'name' => 'execute views_bulk_operations_delete_item',
    'roles' => array(
      'school admin' => 'school admin',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: import import_parents feeds.
  $permissions['import import_parents feeds'] = array(
    'name' => 'import import_parents feeds',
    'roles' => array(
      'school admin' => 'school admin',
    ),
    'module' => 'feeds',
  );

  // Exported permission: import import_staff feeds.
  $permissions['import import_staff feeds'] = array(
    'name' => 'import import_staff feeds',
    'roles' => array(
      'school admin' => 'school admin',
    ),
    'module' => 'feeds',
  );

  // Exported permission: import import_students feeds.
  $permissions['import import_students feeds'] = array(
    'name' => 'import import_students feeds',
    'roles' => array(
      'school admin' => 'school admin',
    ),
    'module' => 'feeds',
  );

  // Exported permission: import import_teachers feeds.
  $permissions['import import_teachers feeds'] = array(
    'name' => 'import import_teachers feeds',
    'roles' => array(
      'school admin' => 'school admin',
    ),
    'module' => 'feeds',
  );

  // Exported permission: read privatemsg.
  $permissions['read privatemsg'] = array(
    'name' => 'read privatemsg',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: reply only privatemsg.
  $permissions['reply only privatemsg'] = array(
    'name' => 'reply only privatemsg',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: set privatemsg e-mail notification level.
  $permissions['set privatemsg e-mail notification level'] = array(
    'name' => 'set privatemsg e-mail notification level',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'pm_email_notify',
  );

  // Exported permission: view roles recipients.
  $permissions['view roles recipients'] = array(
    'name' => 'view roles recipients',
    'roles' => array(
      'principal' => 'principal',
      'school admin' => 'school admin',
      'staff' => 'staff',
      'teacher' => 'teacher',
    ),
    'module' => 'privatemsg_roles',
  );

  // Exported permission: write privatemsg.
  $permissions['write privatemsg'] = array(
    'name' => 'write privatemsg',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: write privatemsg to all roles.
  $permissions['write privatemsg to all roles'] = array(
    'name' => 'write privatemsg to all roles',
    'roles' => array(
      'principal' => 'principal',
      'school admin' => 'school admin',
      'staff' => 'staff',
      'teacher' => 'teacher',
    ),
    'module' => 'privatemsg_roles',
  );

  return $permissions;
}
