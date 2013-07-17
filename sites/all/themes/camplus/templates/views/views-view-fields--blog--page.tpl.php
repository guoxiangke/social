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
?>
<div class="blog-list">
  <div class="submmitted">
    <div class="ym"><?php print format_date($fields['created']->raw, 'custom', 'Y年m月'); ?></div>
    <div class="day"><span><?php print format_date($fields['created']->raw, 'custom', 'd'); ?></span>日</div>
  </div>
  <div class="stbody blog-list-header">
    <div class="stimg stimgL avatar">
      <?php print $fields['picture']->content; ?>
    </div>
    <!-- end user avatar -->
    <div class="sttext">
      <div class="title"><?php print $fields['name']->content; ?></div>
      <h3 class="blog-title"><?php print $fields['title']->content; ?><?php print $fields['timestamp']->content; ?></h3>
    </div>
  </div>
  <!-- end blog  list header -->
  <div class="blog-list-body">
    <?php print $fields['body']->content; ?>
  </div>
  <!-- end blog list body -->
  <div class="blog-list-footer clearfix">
    <ul class="clearfix unstyled blog-handle fr">
      <?php if (isset($fields['ops'])): ?>
        <li><i class="icon icon-like"></i><?php print $fields['ops']->content; ?><?php if(isset($fields['count'])): ?><span class="like-num"><?php print $fields['count']->content; ?></span><?php endif; ?></li>
      <?php endif; ?>
      <?php if (isset($fields['ops_2'])): ?>
        <li><?php print $fields['ops_2']->content; ?></li>
      <?php endif; ?>
      <?php if (isset($fields['uid'])): ?>
      <li><?php print $fields['uid']->content; ?></li>
      <?php endif; ?>
      <li><?php print $fields['comments_link']->content; ?></li>
      <?php if (isset($fields['ops_1'])): ?>
      <li><?php print $fields['ops_1']->content; ?></li>
      <?php endif; ?>
    </ul>
    <?php if (isset($fields['created_1'])): ?>
    <div class="blog-from fl">
      <?php print $fields['created_1']->content; ?>
    </div>
    <?php endif; ?>
  </div>
  <!-- end blog list footer -->
</div>
<!-- blog list -->
