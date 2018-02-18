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

  $thepath = drupal_get_path("module", "home");
  drupal_add_js($thepath . '/js/home.js');
  drupal_add_css($thepath . '/css/home.css');

  $the_word = array(
    0 => array('letter' => 't', 'status' => 0),
    1 => array('letter' => 'e', 'status' => 1),
    2 => array('letter' => 's', 'status' => 0),
    3 => array('letter' => 't', 'status' => 0),
  );

  $words = array(
    array('word' => 'abandon', 'tr' => '放弃'),
    array('word' => 'abase', 'tr' => '降低自己'),
    array('word' => 'abash', 'tr' => '使愧疚'),
    array('word' => 'abate', 'tr' => '减少'),
    array('word' => 'abbreviate', 'tr' => '缩写'),
    array('word' => 'abdicate', 'tr' => '退位'),
    array('word' => 'aberration', 'tr' => '失常'),
    //array('word' => '', 'translation' => ''),
  );
  shuffle($words);

  drupal_add_js(array('word_info' => array(
    'the_word' => $the_word,
    'words' => $words,
  )), 'setting');

  $vars['letters'] = $the_word;

  $vars['totle_number'] = count($words);


  /*
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'ding_yue_hao')
        ->propertyCondition('status', NODE_PUBLISHED)
        ->propertyOrderBy('created', 'DESC')
        ->count()
        ->addMetaData('account', user_load(1));
  $number = $query->execute();
   */


  return theme('template_home', $vars);
}


