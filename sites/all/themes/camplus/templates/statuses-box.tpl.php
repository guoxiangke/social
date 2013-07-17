<?php
?>
<div class="block block-weibo mbl">
  <h2 class="block-title ir icon mbm">有什么新鲜事想告诉大家</h2>
  <div class="block-content">
    <div class="input mbs">
      <textarea name="fbss-status" id="" cols="30" rows="10" class="form-text"></textarea>
      <span class="icon ir icon-arrow">arrow</span>
    </div>
    <?php print drupal_render($form['form_build_id']); ?>
    <?php print drupal_render($form['form_id']); ?>
    <?php print drupal_render($form['form_token']); ?>
    <?php print drupal_render($form['actions']); ?>
    <div class="func_area clearfix">
      <?php print drupal_render($form['fbss-submit']); ?>
      <?php print drupal_render($form['fbsmp']); ?>
    </div>
  </div>
</div>
