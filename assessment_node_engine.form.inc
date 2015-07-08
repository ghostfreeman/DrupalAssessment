<?php
/**
 * Implements the form to create and edit the custom articles.
 */
function assessment_node_engine_form($form, &$form_state) {
  global $user;
  $form = array();
  //$defaults =

  $form['title'] = array(
    '#type' => 'textfield',
    //'#default_value' =>
    '#description' => t('Title'),
  );

  $form['bodytext'] = array(
    '#type' => 'textarea',
    "#title" => t("Body"),
    //"#default_value" =>
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
  dpm($form, "Form");
  $save_status = assessment_node_engine_save_article($user->uid, $form['title']['#value'], $form['bodytext']['#value']);
  drupal_set_message(t("Your article has been created"));
}
