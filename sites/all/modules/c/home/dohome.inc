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
    array('word' => 'abandon', 'pos' => 2),
    array('word' => 'abase', 'pos' => 3),
    array('word' => 'abash', 'translation' => ''),
    array('word' => 'abate', 'translation' => ''),
    array('word' => 'abbreviate', 'translation' => ''),
    array('word' => 'abdicate', 'translation' => ''),
    array('word' => 'aberration', 'translation' => '失常'),
    //array('word' => '', 'translation' => ''),
  );
  shuffle($words);

  drupal_add_js(array('word_info' => array(
    'the_word' => $the_word,
    'words' => $words,
  )), 'setting');

  $vars['letters'] = $the_word;


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


