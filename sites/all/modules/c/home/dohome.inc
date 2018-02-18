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
  $words1 = get_all_words();
  dpm($words1);

  $words = array(
    array('word' => 'abandon', 'tr' => '放弃'),
    array('word' => 'abase', 'tr' => '降低自己'),
    array('word' => 'abash', 'tr' => '使愧疚'),
    array('word' => 'abate', 'tr' => '减少'),
    array('word' => 'abbreviate', 'tr' => '缩写'),
    array('word' => 'abdicate', 'tr' => '退位'),
    array('word' => 'aberration', 'tr' => '失常'),
    array('word' => 'aberration', 'tr' => '失常'),
    array('word' => 'abet', 'tr' => '教唆'),
    array('word' => 'abject', 'tr' => '卑贱的'),
    array('word' => 'abjure', 'tr' => '避免'),
    array('word' => 'ablution', 'tr' => '清洗'),
    array('word' => 'abnormal', 'tr' => '反常的'),
    array('word' => 'abominate', 'tr' => '痛恨'),
    array('word' => 'aboriginal', 'tr' => '土著'),
    array('word' => 'abridge', 'tr' => '删节'),
    //array('word' => '', 'tr' => ''),
  );
  shuffle($words);


  drupal_add_js(array('word_info' => array(
    'the_word' => $the_word,
    'words' => $words,
  )), 'setting');

  $vars['letters'] = $the_word;

  $vars['totle_number'] = count($words);



  return theme('template_home', $vars);
}


/*
 * Retrieve all words.
 */
function get_all_words() {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'word')
        ->propertyCondition('status', NODE_PUBLISHED)
        ->addMetaData('account', user_load(1));
  $result = $query->execute();

  $words = array();
  if (isset($result['node'])) {
    $node_nids = array_keys($result['node']);
    $words_nodes = entity_load('node', $node_nids);
    foreach ($words_nodes as $word_node) {
      $quer = new EntityFieldQuery();
      $quer->entityCondition('entity_type', 'node')
           ->entityCondition('bundle', 'explanation')
           ->propertyCondition('status', NODE_PUBLISHED)
           ->fieldCondition('field_word', 'target_id', $word_node->nid)
           ->addMetaData('account', user_load(1));
      $resul = $quer->execute();
      $explanation = '';
      if (isset($resul['node'])) {
        $nids = array_keys($resul['node']);
        $expla = entity_load('node', $nids[0]);
        $body = field_get_items('node', $expla, 'body');
        $explanation = $body[0]['value'];
      }

      $words[] = array('word' => $word_node->title, 'tr' => '', 'explanation' => $explanation);
    }
    shuffle($words);
  }
  return $words;
}

