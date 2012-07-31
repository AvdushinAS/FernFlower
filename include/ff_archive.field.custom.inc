<?php
/* @file
 * 
 * File contains hook implementations for 'XXX' field type
 */

/**
 * Returns field description for 'XXX' field type
 * @return array
 */
function XXX_get_field_info() {
  // TODO: Add code here
  return array (
    'label' => t('XXX'),
    'description' => t('Field stores the information about XXX'),
    'instance_settings' => array (),
    'default_widget' => 'XXX_widget',
    'default_formatter' => 'XXX_formatter',
  );
}

/**
 * Returns field structure schema for 'XXX' field type
 * @return array
 */
function XXX_get_schema() {
  // TODO: Add code here
  return $schema;
}

/**
 * Implements hook_is_empty for 'XXX' field type
 * @param type $item
 * @return boolean
 */
function XXX_is_empty($item) {
  // TODO: Add code here
  return TRUE;
}

function XXX_validate($entity_type, $entity, $field, $instance, $langcode, 
                          $items, &$errors) {
  // TODO: Add code here
}

/**
 * Returns widget description for 'XXX' field type
 * @return array
 */
function XXX_get_widget(){
  // TODO: Add code here
  return array (
    'label' => t('XXX widget'),
    'description' => t('Allows the user to enter XXX'),
    'field types' => array('XXX'),
    'behaviors' => array(
      'multiple values' => FIELD_BEHAVIOR_DEFAULT,
      'default value' => FIELD_BEHAVIOR_DEFAULT,
    ),
  );
}

/**
 * Returns widget form description for 'XXX_widget'
 * @param type $form
 * @param type $form_state
 * @param type $field
 * @param type $instance
 * @param type $langcode
 * @param type $items
 * @param type $delta
 * @param type $element
 * @return array
 */
function XXX_get_widget_form(&$form, &$form_state, $field, $instance, 
                                  $langcode, $items, $delta, $element) {
  // TODO: Add code here
  return $element;
}

/**
 * Returns formatter description for 'XXX' field type
 * @return array
 */
function XXX_get_formatter() {
  // TODO: Add code here
  return array (
    'label' => t('XXX_formatter'),
    'field types' => array('XXX'),
  );
}

/**
 * Implements hook_field_formatter_view
 * @param type $entity_type
 * @param type $entity
 * @param type $field
 * @param type $instance
 * @param type $langcode
 * @param type $items
 * @param type $display
 * @return string
 */
function XXX_formatter_view($entity_type, $entity, $field, $instance, 
                                $langcode, $items, $display) {
  // TODO: Add code here
  return $element;
}

?>

