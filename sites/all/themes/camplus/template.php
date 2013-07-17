<?php

/**
 * Register template for user login form.
 */
function camplus_theme($existing, $type, $theme, $path){
  return array(
    'user_login' => array(
      'render element' => 'form',
      'path' => drupal_get_path('theme', 'camplus') . '/templates',
      'template' => 'user-login',
    ),
    'statuses_box' => array(
      'render element' => 'form',
      'path' => drupal_get_path('theme', 'camplus') . '/templates',
      'template' => 'statuses-box',
    ),
  );
}
/**
 * Alter user login form submit button class.
 */
function camplus_preprocess_user_login(&$variables) {
  $variables['form']['actions']['submit']['#attributes']['class'] = array('btn', 'btn-login');
}

function camplus_menu_tree__main_menu($variables) {
  return '<ul id="nav" class="clearfix unstyled fl" rel="navigation">' . $variables['tree'] . '</ul>';
}
function camplus_menu_tree__main_menu_sub($variables) {
  return '<ol class="sub-menu unstyled">' . $variables['tree'] . '</ol>';
}
function camplus_menu_link__main_menu($variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $element['#attributes']['class'][] = "haschild";
    $element['#below']['#theme_wrappers'][0] = 'menu_tree__main_menu_sub';
    $sub_menu = drupal_render($element['#below']);
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function camplus_menu_tree__user_menu($variables) {
  return '<ul class="secondary-menu unstyled clearfix fl">' . $variables['tree'] . '</ul>';
}
function camplus_menu_link__user_menu($variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function camplus_links__locale_block($variables) {
  global $language;
  unset($variables['links'][$language->language]);

  return theme('links', $variables);
}

