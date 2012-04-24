<?php
/**
 * @file
 * Administration settings pages
 */

/**
 * Implementation of page callback for settings.
 */
function hidden_nodes_setting_page($form, &$form_state) {
  $form = array();
  foreach (node_type_get_types() as $type_data) {
    $types[$type_data->type] = $type_data->name;
  }
  $form['hidden_nodes_types'] = array(
    '#type' => 'select',
    '#options' => $types,
    '#title' => t('Types to hide'),
    '#description' => t("Select the content types that are allowed to be hidden."),
    '#default_value' => variable_get('hidden_nodes_types', array()),
    '#multiple' => TRUE,
  );
  // To users who can view hidden nodes.
  $form['hidden_nodes_show_message'] = array(
    '#type' => 'checkbox',
    '#title' => t("Display a message if the current content is hidden."),
    '#description' => t("A message will be displayed when viewing full nodes that are hidden."),
    '#default_value' => variable_get('hidden_nodes_show_message', 1),
  );
  $form['hidden_nodes_show_partial_message'] = array(
    '#type' => 'checkbox',
    '#title' => t("Display message if some of a page's content is hidden."),
    '#description' => t("A message will be displayed when viewing pages where only some of a page's content may be hidden, such as Views containing hidden content."),
    '#default_value' => variable_get('hidden_nodes_show_partial_message', 0),
  );
  $form['hidden_nodes_show_parent_message'] = array(
    '#type' => 'checkbox',
    '#title' => t("Display a message if content is hidden because it has some parent content that is hidden."),
    '#description' => t("A message will be displayed for Book content that has hidden parent content."),
    '#default_value' => variable_get('hidden_nodes_show_parent_message', 1),
  );
  return system_settings_form($form);
}
