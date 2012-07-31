<?php
/* @file
 * 
 * File contains hook implementations for 'shedule' field type
 */

/**
 * Returns field description for 'shedule' field type
 * @return array
 */
function shedule_get_field_info() {
  return array (
    'label' => t('Shedule'),
    'description' => t('Field stores the information about fact\'s shedule'),
    'instance_settings' => array (),
    'default_widget' => 'shedule_widget',
    'default_formatter' => 'shedule_formatter',
  );
}

/**
 * Returns field structure schema for 'shedule' field type
 * @return array
 */
function shedule_get_schema() {
  $schema['columns']['datetime'] = array (
    'description' => t('The Unix timestamp when the fact was happened'),
    'type' => 'int',
    'not null' => TRUE,
    'default' => 0,
  );
  $schema['columns']['interval'] = array (
    'description' => t('The Unix timestamp to store time interval for regular facts'),
    'type' => 'int',
    'not null' => FALSE,
  );
  $schema['indexes'] = array (
    'fact_date' => array('datetime'),
    'fact_interval' => array('interval'),
  );
  return $schema;
}

/**
 * Implements hook_is_empty for 'shedule' field type
 * @param type $item
 * @return boolean
 */
function shedule_is_empty($item) {
  return empty($item['datetime']);
}

function shedule_validate($entity_type, $entity, $field, $instance, $langcode, 
                          $items, &$errors) {

}

/**
 * Returns widget description for 'shedule' field type
 * @return array
 */
function shedule_get_widget(){
  return array (
    'label' => t('Shedule widget'),
    'description' => t('Allows the user to enter fact\'s shedule'),
    'field types' => array('shedule'),
    'behaviors' => array(
      'multiple values' => FIELD_BEHAVIOR_DEFAULT,
      'default value' => FIELD_BEHAVIOR_DEFAULT,
    ),
  );
}

/**
 * Returns widget form description for 'shedule_widget'
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
function shedule_get_widget_form(&$form, &$form_state, $field, $instance, 
                                  $langcode, $items, $delta, $element) {

  $widget = $element;
  $widget += array(
    '#type' => 'fieldset',
    '#title' => t('Shedule'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $widget['datetime'] = array(
    '#type' => 'date_text',
    '#title' => t('Date and time'),
    '#default_value' => isset($items[$delta]['datetime']) ?
                              $items[$delta]['datetime'] : 0,
  );
  $widget['regular'] = array(
    '#type' => 'checkbox',
    '#title' => t('Is regular'),
    '#default_value' => isset($items[$delta]['interval']),
  );
  $regular_name = sprintf('%s[%s][%d][shedule][regular]', $element['#field_name'],
                                                          $element['#language'],
                                                          $element['#delta']);
  $widget['interval'] = array(
    '#type' => 'date_text',
    '#title' => t('Repeat interval'),
    '#default_value' => isset($items[$delta]['interval']) ?
                              $items[$delta]['interval'] : 0,
    '#states' => array(
      'visible' => array(
        ':input[name="' . $regular_name .'"]'  => array('checked' => TRUE),
      ),
    ),
  );
  $element['shedule'] = $widget;
  return $element;
}

/**
 * Returns formatter description for 'shedule' field type
 * @return array
 */
function shedule_get_formatter() {
  return array (
    'label' => t('Simple text-based formatter'),
    'field types' => array('shedule'),
  );
}

function shedule_formatter_view($entity_type, $entity, $field, $instance, 
                                $langcode, $items, $display) {
  $element = array();
  foreach ($items as $delta => $item) {
    $output = $item['datetime'];
    if(!empty($item['interval']))
      $output .= t('Interval') . ': ' . $item['interval'];
    $element[$delta] = array('#markup' => $output);
  }
  return $element;
}

?>

