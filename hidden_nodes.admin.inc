<?php

/**
 * Implementation of page callback for settings.
 */
function hidden_nodes_setting_page() {
  $form = array();
	foreach (node_get_types() as $type => $name) {
    $types[] = $type;
  }
	$form['types'] = array(
	  '#type' => 'select',
		'#options' => $types,
		'#title' => t('Types to hide'),
		'#description' => t("Select the types that are allowed to be hidden from users that don't have permission to view hidden content."),
		'#multiple' => TRUE,
  );
	return system_settings_form($form);
	return $form;
}