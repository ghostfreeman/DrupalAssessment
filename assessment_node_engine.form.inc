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
    '#title' => t('Title'),
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

  $form['#submit'] = array();

  return $form;
}

/**
 * This is a validation function scaffold for the above form. Since its a
 * scaffold, nothing is used.
 */
function assessment_node_engine_form($form, &$form_state) {

}

/**
 * Save all changes to the database and then returns to the home page with a
 * message statign the changes have been saved
 */
function assessment_node_engine_form_submit($form, &$form_state) {
  global $user;
  //$save_status = twc_block_demo_form_save_message($user->uid, $form_state['values']['message']);
  drupal_set_message(t("Your article has been created"));
}

/**
 * Look up the database for any existing field entries. If they exist, send them
 * back.
 */
function assessment_node_engine_form_submit($user_id) {
  $results = db_query("SELECT message FROM {login_messages} WHERE user_id = :n_user_id", array(":n_user_id" => $user_id));

  foreach ($results as $result) {
    $message = $result->message;
  }

  if(isset($message)) {
    return $message;
  } else {
    return null;
  }
}
