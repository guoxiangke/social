<?php

/**
 * @file
 * Administration page callbacks for Moodle courses list.
 */

/**
 * Implements hook_admin_settings().
 */
function moodle_course_admin_form() {

  /*$form['moodle_course_termcoursefilter'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable term course filter'),
    '#default_value' => variable_get('moodle_course_termcoursefilter', TRUE),
  );	*/

  $form['moodle_course_termmode'] = array(
    '#type' => 'select',
    '#title' => t('Term mode'),
    '#description' => t('Term mode'),
    '#options' => array(1=>'Academic year', 2=>'Semester', 3=>'Tertial', 4=>'Trimester'),
    '#default_value' => variable_get('moodle_course_termmode', 2),
  );
  $form['moodle_course_termcoursefilterdisplayname'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Term course filter display name'),
    '#default_value' => t(variable_get('moodle_course_termcoursefilterdisplayname', 'Term')),
    '#description'   => t("Term course filter display name"),
    '#size'          => 20,
    '#required'      => TRUE,
  );
  $form['moodle_course_term1name'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Term 1 name'),
    '#default_value' => t(variable_get('moodle_course_term1name', 'Term 1')),
    '#description'   => t('The name of term 1.'),
    '#required'      => TRUE,
  );
  $form['moodle_course_term2name'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Term 2 name'),
    '#default_value' => t(variable_get('moodle_course_term2name', 'Term 2')),
    '#description'   => t('The name of term 2.'),
    '#size'          => 20,
    '#required'      => FALSE,
  );
  $form['moodle_course_term3name'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Term 3 name'),
    '#default_value' => t(variable_get('moodle_course_term3name', 'Term 3')),
    '#description'   => t('The name of term 3.'),
    '#required'      => FALSE,
  );
  $form['moodle_course_term4name'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Term 4 name'),
    '#default_value' => t(variable_get('moodle_course_term4name', 'Term 4')),
    '#description'   => t('The name of term 4.'),
    '#size'          => 20,
    '#required'      => FALSE,
  );
  $form['moodle_course_term1startday'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Term 1 start day'),
    '#default_value' => variable_get('moodle_course_term1startday', '03-01'),
    '#description'   => t('Format:Month-Day,For example: 03-01'),
    '#size'          => 5,
    '#required'      => TRUE,
  );
  $form['moodle_course_term2startday'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Term 2 start day'),
    '#default_value' => variable_get('moodle_course_term2startday', '09-01'),
    '#description'   => t('Format:Month-Day,For example: 09-01'),
    '#size'          => 5,
    '#required'      => FALSE,
  );
  $form['moodle_course_term3startday'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Term 3 start day'),
    '#default_value' => variable_get('moodle_course_term3startday', '07-01'),
    '#description'   => t('Format:Month-Day,For example: 07-01'),
    '#size'          => 5,
    '#required'      => FALSE,
  );
  $form['moodle_course_term4startday'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Term 4 start day'),
    '#default_value' => variable_get('moodle_course_term4startday', '10-01'),
    '#description'   => t('Format:Month-Day,For example: 10-01'),
    '#size'          => 5,
    '#required'      => FALSE,
  );

  return system_settings_form($form);
}
