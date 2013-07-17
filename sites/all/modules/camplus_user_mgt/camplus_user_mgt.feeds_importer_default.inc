<?php
/**
 * @file
 * camplus_user_mgt.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function camplus_user_mgt_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_parents';
  $feeds_importer->config = array(
    'name' => 'Import Parents',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          243709442 => '243709442',
          66784200 => 0,
          150186561 => 0,
          166149871 => 0,
          29092273 => 0,
          7712643 => 0,
          228690954 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'username',
            'target' => 'name',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'password',
            'target' => 'pass',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'lastname',
            'target' => 'field_last_name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'firstname',
            'target' => 'field_first_name',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'email',
            'target' => 'mail',
            'unique' => 1,
          ),
          5 => array(
            'source' => 'children',
            'target' => 'field_children:label',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_parents'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_staff';
  $feeds_importer->config = array(
    'name' => 'Import Staff',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          166149871 => '166149871',
          66784200 => 0,
          243709442 => 0,
          150186561 => 0,
          29092273 => 0,
          7712643 => 0,
          228690954 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'username',
            'target' => 'name',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'password',
            'target' => 'pass',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'lastname',
            'target' => 'field_last_name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'firstname',
            'target' => 'field_first_name',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'email',
            'target' => 'mail',
            'unique' => 1,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_staff'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_students';
  $feeds_importer->config = array(
    'name' => 'Import Students',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          66784200 => '66784200',
          243709442 => 0,
          150186561 => 0,
          166149871 => 0,
          29092273 => 0,
          7712643 => 0,
          228690954 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'username',
            'target' => 'name',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'password',
            'target' => 'pass',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'classid',
            'target' => 'field_classid',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'lastname',
            'target' => 'field_last_name',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'firstname',
            'target' => 'field_first_name',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'email',
            'target' => 'mail',
            'unique' => 1,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_students'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_teachers';
  $feeds_importer->config = array(
    'name' => 'Import Teachers',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          150186561 => '150186561',
          66784200 => 0,
          243709442 => 0,
          166149871 => 0,
          29092273 => 0,
          7712643 => 0,
          228690954 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'username',
            'target' => 'name',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'password',
            'target' => 'pass',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'lastname',
            'target' => 'field_last_name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'firstname',
            'target' => 'field_first_name',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'email',
            'target' => 'mail',
            'unique' => 1,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_teachers'] = $feeds_importer;

  return $export;
}
