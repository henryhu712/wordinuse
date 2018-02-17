<?php

/**
 * @file
 * Front page.
 */

/**
 * Home
 */
function home_content() {

  global $user;

  $vars = array();

/*
  $thepath = drupal_get_path("module", "home");
  drupal_add_js($thepath . '/js/n_more.js');
  drupal_add_css($thepath . '/css/news.css');

  $data = home_get_collection_of_NewsLink_data(0, $language->language);

  drupal_add_js(array('news_args' => array(
      'lang_code' => $language->language,
      'lang_prefix' => $language->prefix,
      'item_array' => $data,
  )), 'setting');

  $vars = array(
    'news_array' => $data,
  );
*/

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'ding_yue_hao')
        ->propertyCondition('status', NODE_PUBLISHED)
        ->propertyOrderBy('created', 'DESC')
        ->count()
        ->addMetaData('account', user_load(1));
  $number = $query->execute();


  $vars['number_ding_yue_hao'] = $number;

  return theme('template_home', $vars);
}


