<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */

	// $comment = new stdClass;
	// $comment->nid = $row->nid;
	// $form = drupal_get_form('comment_form', $comment);

?>
<?php foreach ($fields as $id => $field): ?>
  <?php if (!empty($field->separator)): ?>
    <?php print $field->separator; ?>
  <?php endif; ?>

  <?php print $field->wrapper_prefix; ?>
    <?php print $field->label_html; ?>
    <?php print $field->content; ?>
  <?php print $field->wrapper_suffix; ?>
<?php endforeach; ?>

<?php
foreach ( $view->result as $q_a_item) {//both for question & answers.
 if(isset($q_a_item->comments) && $row->nid == $q_a_item->comments['#form']['nid']['#value']){
   ?>
   <div class="comments">
     <?php print render($q_a_item->comments['#content']);?>
     <div class="clearfix">
      <div class="q-feedback">
        <a class="comment_button btn btn-mini" data-trigger="click" data-placement='bottom'><i class="icon-comments icon-small"></i>Comment</a>
      </div>
    
     </div>
     
    <div class="comment_textarea">
      <a href="#" class="close"><i class="icon-remove-sign"></i></a>
      <?php print (render($q_a_item->comments['#form'])); ?>
    </div>
   </div>
   <?php
   }
}
?>