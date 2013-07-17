<?php
/**
 * @file
 * camplus_user_mgt.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function camplus_user_mgt_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_parents-children-explode';
  $feeds_tamper->importer = 'import_parents';
  $feeds_tamper->source = 'children';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Explode';
  $export['import_parents-children-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_parents-children-find_replace';
  $feeds_tamper->importer = 'import_parents';
  $feeds_tamper->source = 'children';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => ' ',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['import_parents-children-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_parents-children-rewrite';
  $feeds_tamper->importer = 'import_parents';
  $feeds_tamper->source = 'children';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[children]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['import_parents-children-rewrite'] = $feeds_tamper;

  return $export;
}
