<?php

/**
 * @file
 * Administration forms and submit handling for isMemberOfSite module.
 */

/**
 * Administration and configuration form for memberofsite.
 *
 * @ingroup forms
 *
 * @todo break out non-settings elements into their own form.
 *
 * @return array
 *   The Drupal form definition.
 */
function islandora_datastream_filenamer_admin_form() {
  $form = array(
    'islandora_ds_download' => array(
      '#type' => 'fieldset',
      '#title' => t('Datastream Configuration'),
      'islandora_ds_download_filename_pattern' => array(
        '#type' => 'textfield',
        '#title' => t('Datastream download filename pattern'),
        '#description' => t('Optionally control the filenames assigned to datastream downloads.  Filename naming pattern should end with the file extension or [dsfilename:extension].'),
        '#default_value' => variable_get('islandora_ds_download_filename_pattern'),
        '#maxlength' => 255,
      ),
      'token_help' => array(
        '#title' => t('Replacement patterns'),
        '#type' => 'fieldset',
        '#collapsible' => FALSE,
        '#collapsed' => FALSE,
        'help' => array(
          '#theme' => 'token_tree',
          '#token_types' => array('dsfilename', 'fedora'),
        ),
      ),
    ),
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Save configuration'),
    ),
    'reset' => array(
      '#type' => 'submit',
      '#value' => t('Reset to defaults'),
    ),
  );
  return $form;
}

/**
 * Function that sets the Drupal variables with user's input.
 *
 * @param array $form
 *   The Drupal form definition.
 * @param array $form_state
 *   The Drupal form state.
 */
function islandora_datastream_filenamer_admin_form_submit(array $form, array &$form_state) {
  drupal_set_message(t('The settings have been updated!'));
  $id = $form_state['triggering_element']['#id'];
  switch ($id) {
    case 'edit-submit':
      variable_set('islandora_ds_download_filename_pattern', $form_state['values']['islandora_ds_download_filename_pattern']);
      break;

    case 'edit-reset':
      variable_del('islandora_ds_download_filename_pattern');
      break;
  }
}

