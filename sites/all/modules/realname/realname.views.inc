<?php

/**
 * @file
 * Views integration for the realname module.
 */

/**
 * Implements hook_views_data().
 */
function realname_views_data() {
  $data['realname']['table']['group']  = t('Realname');
  $data['realname']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function realname_views_data_alter(&$data) {
  $data['users']['username'] = array(
    'title' => t('Username'),
    'help' => t("The user or author username."),
    'real field' => 'name',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
  );
}
