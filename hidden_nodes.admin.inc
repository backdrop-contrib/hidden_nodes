<?php
/**
 * @file
 * Administration settings pages
 */

/**
 * Implementation of page callback for settings.
 */
function hidden_nodes_setting_page($form, &$form_state) {
  $config = config('hidden_nodes.settings');
  $form = array();
  $form['#config'] = 'hidden_nodes.settings';
  // allow for people like chrisferagotti to hijack the
  // intention of these "sweet lines of code" by setting priority
  // back to 0 so that it aligns with everything else in the world
  // default is still 1000

  $priorities = array(
    0 => 0,
    10 => 10,
    100 => 100,
    1000 => 1000,
  );
  $form['priority'] = array(
    '#type' => 'select',
    '#options' => $priorities,
    '#title' => t('Node Grants Priority'),
    '#description' => t("Priority to give hidden nodes in the granting of permissions, set this to 0 to avoid conflicts with other projects (like TAC). 1000 is the default in order to take priority over all other grant methods."),
    '#default_value' => $config->get('priority'),
  );
  foreach (node_type_get_types() as $type_data) {
    $types[$type_data->type] = $type_data->name;
  }
  $form['types'] = array(
    '#type' => 'select',
    '#options' => $types,
    '#title' => t('Types to hide'),
    '#description' => t("Select the content types that are allowed to be hidden."),
    '#default_value' => $config->get('types'),
    '#multiple' => TRUE,
  );

  $form['apply_styles'] = array(
    '#type' => 'checkbox',
    '#title' => t("Use this module's styles for hidden content and menu links to hidden content."),
    '#description' => t("Apply the CSS rules supplied with this module.  Note: these rules may not affect display if overridden in theme."),
    '#default_value' => $config->get('apply_styles'),
  );

  $form['content'] = array(
    '#type' => 'fieldset',
    '#title' => t('Hidden full node message'),
  );
  $form['content']['show_message'] = array(
    '#type' => 'checkbox',
    '#title' => t("Display a message if the current content is hidden."),
    '#description' => t("A message will be displayed when viewing full nodes that are hidden."),
    '#default_value' => $config->get('show_message'),
  );
  $form['content']['message'] = array(
    '#type' => 'textfield',
    '#title' => t('Message'),
    '#default_value' => check_plain($config->get('message')),
    '#size' => 90,
    '#maxlength' => 128,
  );

  $form['partial_content'] = array(
    '#type' => 'fieldset',
    '#title' => t('Hidden partial content message'),
  );
  $form['partial_content']['show_partial_message'] = array(
    '#type' => 'checkbox',
    '#title' => t("Display message if some of a page's content is hidden."),
    '#description' => t("A message will be displayed when viewing pages where only some of a page's content may be hidden, such as Views containing hidden content."),
    '#default_value' => $config->get('show_partial_message'),
  );
  $form['partial_content']['partial_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Message'),
    '#default_value' => check_plain($config->get('partial_message')),
    '#size' => 90,
    '#maxlength' => 128,
  );

  $form['parent_content'] = array(
    '#type' => 'fieldset',
    '#title' => t('Hidden parent content message'),
  );
  $form['parent_content']['show_parent_message'] = array(
    '#type' => 'checkbox',
    '#title' => t("Display a message if Book content has some parent content that is hidden."),
    '#description' => t("A message will be displayed for Book content that has hidden parent content."),
    '#default_value' => $config->get('show_parent_message'),
  );
  $form['parent_content']['parent_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Message'),
    '#default_value' => check_plain($config->get('parent_message')),
    '#size' => 90,
    '#maxlength' => 128,
  );

  return system_settings_form($form);
}
