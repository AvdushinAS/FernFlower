<?php
/* @file
 * 
 * File contains hook implementations for 'participant' field type
 */

/**
 * Returns field description for 'participant' field type
 * @return array
 */
function participant_get_field_info() {
  return array (
    'label' => t('Participant'),
    'description' => t('Stores information about fact\'s participant'),
    'instance_settings' => array (),
    'default_widget' => 'participant_widget',
    'default_formatter' => 'participant_formatter',
  );
}

/**
 * Returns field structure schema for 'participant' field type
 * @return array
 */
function participant_get_schema() {
  $schema['columns']['type'] = array(
    'description' => t('Participant\'s type'),
    'type' => 'serial',
    'size' => 'tiny',
    'not null' => TRUE,
    'default' => 0
  );
  $schema['columns']['first_name'] = array(
    'description' => t('Participant\'s first name'),
    'type' => 'text',
    'size' => 'tiny',
    'not null' => FALSE,
    'default' => '',
  );
  $schema['columns']['secont_name'] = array(
    'description' => t('Participant\'s second name'),
    'type' => 'text',
    'size' => 'tiny',
    'not null' => FALSE,
    'default' => '',
  );
  $schema['columns']['last_name'] = array(
    'description' => t('Participant\'s last name'),
    'type' => 'text',
    'size' => 'tiny',
    'not null' => FALSE,
    'default' => '',
  );
  $schema['columns']['birthdate'] = array(
    'description' => t('Participant\'s birthdate'),
    'type' => 'date',
    'not null' => FALSE,
    'default' => 0,
  );
  $schema['columns']['sex'] = array(
    'description' => t('Participant\'s sex'),
    'type' => 'serial',
    'size' => 'tiny',
    'not null' => TRUE,
    'default' => 0
  );
  $schema['columns']['contact'] = array(
    'description' => t('Participant\'s contact info'),
    'type' => 'text',
    'size' => 'medium',
    'not null' => FALSE,
    'default' => '',
  );
  $schema['columns']['statement'] = array(
    'description' => t('Participant\'s statement'),
    'type' => 'text',
    'size' => 'medium',
    'not null' => FALSE,
    'default' => '',
  );
  $schema['columns']['comments'] = array(
    'description' => t('Comments about participant'),
    'type' => 'text',
    'size' => 'medium',
    'not null' => FALSE,
    'default' => '',
  );
  $schema['indexes'] = array(
    'participant_type' => array('type'),
    'participant_last_name' => array('last_name'),
    'participant_birthdate' => array('birthdate'),
    'participant_sex' => array('sex'),
  );
  return $schema;
}

/**
 * Implements hook_is_empty for 'participant' field type
 * @param type $item
 * @return boolean
 */
function participant_is_empty($item) {
  return empty($item['type']);
}

function participant_validate($entity_type, $entity, $field, $instance, $langcode, 
                          $items, &$errors) {
  // TODO: Add code here
}

/**
 * Returns widget description for 'participant' field type
 * @return array
 */
function participant_get_widget(){
  return array (
    'label' => t('Participant widget'),
    'description' => t('Allows the user to enter participant info'),
    'field types' => array('participant'),
    'behaviors' => array(
      'multiple values' => FIELD_BEHAVIOR_DEFAULT,
      'default value' => FIELD_BEHAVIOR_DEFAULT,
    ),
  );
}

/**
 * Returns widget form description for 'participant_widget'
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
function participant_get_widget_form(&$form, &$form_state, $field, $instance, 
                                  $langcode, $items, $delta, $element) {
  $widget = $element;
  $widget += array(
    '#type' => 'fieldset',
    '#title' => t('Participants'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $widget['last_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Last name'),
    '#maxlength' => '30',
  );
  $widget['first_name'] = array(
    '#type' => 'textfield',
    '#title' => t('First name'),
    '#maxlength' => '30',
  );
  $widget['secont_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Second name'),
    '#maxlength' => '30',
  );
  $widget['birthdate'] = array(
    '#type' => 'date_select',
    '#title' => t('Birth date'),
    '#default_value' => '0',
  );
  $element['participant'] = $widget;
  return $element;
}

/**
 * Returns formatter description for 'participant' field type
 * @return array
 */
function participant_get_formatter() {
  return array (
    'label' => t('Participant formatter'),
    'field types' => array('participant'),
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
function participant_formatter_view($entity_type, $entity, $field, $instance, 
                                $langcode, $items, $display) {
  // TODO: Add code here
  return $element;
}

?>

