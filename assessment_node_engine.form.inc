<?php
/**
 * Implements the form to create and edit the custom articles.
 */
function assessment_node_engine_form($form, &$form_state, $article_id=NULL) {
  $form = array();

  if(!(is_null($article_id))) {
    $defaults = assessment_node_engine_find_existing($article_id);
  }

  $form['title'] = array(
    '#type' => 'textfield',
    "#title" => t("Title"),
    '#default_value' => (isset($defaults->title) ? $defaults->title : ""),
  );

  $form['bodytext'] = array(
    '#type' => 'textarea',
    "#title" => t("Body"),
    "#default_value" => (isset($defaults->bodytext) ? $defaults->bodytext : ""),
  );

  $form['article_id'] = array(
    '#type' => 'hidden',
    "#default_value" => (isset($defaults->article_id) ? $defaults->article_id : ""),
  );

  $form['actions'] = array(
    '#type' => 'actions'
  );

  $form['actions']['submit'] = array(
    "#type" => 'submit',
    "#value" => t('Save'),
  );

  $form['#submit'] = array('assessment_node_engine_form_submit');

  return $form;
}

/**
 * This is a validation function scaffold for the above form. Since its a
 * scaffold, nothing is used.
 */
function assessment_node_engine_form_validate($form, &$form_state) {

}

/**
 * Save all changes to the database and then returns to the home page with a
 * message statign the changes have been saved
 */
function assessment_node_engine_form_submit($form, &$form_state) {
  global $user;

  if ($form['article_id']['#value'] != "") {
    //Editing existing article
    $save_status = assessment_node_engine_save_article($user->uid, $form['title']['#value'], $form['bodytext']['#value'], NULL, NULL, $form['article_id']['#value']);
    drupal_set_message(t("Your article has been revised"));
  } else {
    //saving new article
    $save_status = assessment_node_engine_save_article($user->uid, $form['title']['#value'], $form['bodytext']['#value']);
    drupal_set_message(t("Your article has been created"));
  }

  drupal_goto("my-node-system/".$form['article_id']['#value']);
}
