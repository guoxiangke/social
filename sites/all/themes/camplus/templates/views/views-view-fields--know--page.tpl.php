<?php
// picture
// title
// timestamp
// field_subject
// name
// last_updated
// body
// comment_count
// counter
// field_tags
?>
<div class="stbody views-row view-question">
  <div class="picture stimg stimgL avatar"><?php print $fields['picture']->content; ?></div>
  <div class="sttext">
    <div class="question">
      <div class="title clearfix">
        <?php print $fields['title']->content; ?>
        <span class="field-subject">/<?php print $fields['field_subject']->content; ?></span>
        <?php if (isset($fields['new_comments'])): ?>
          <span class="new-comments">(<?php print $fields['new_comments']->content; ?>)</span>
        <?php endif; ?>
        <?php if (isset($fields['timestamp'])): ?>
          <span class="timestamp"><?php print $fields['timestamp']->content; ?></span>
        <?php endif; ?>
      </div>
      <div class="name">
        <?php print $fields['name']->content; ?>
        <?php if (isset($fields['last_updated'])) print $fields['last_updated']->content; ?>
      </div>
      <div class="body"><?php print $fields['body']->content; ?></div>
      <div class="field-tags"><?php print $fields['field_tags']->content; ?></div>
    </div>
    <div class="question-status">
      <?php if (isset($fields['field_best_answer'])): ?>
        <div class="solved">
          <?php print $fields['field_best_answer']->content; ?>
        </div>
      <?php else: ?>
        <div class="unsolved">Unsolved</div>
      <?php endif; ?>
    </div>
    <div class="counter">
      <?php if (isset($fields['totalcount'])): ?>
        <div class="view-counter counter-item">
          <?php print $fields['totalcount']->content; ?>
          <span class="counters"><?php print $fields['totalcount']->raw > 1 ? t('Reads') : t('Read'); ?></span>
        </div>
      <?php endif; ?>
      <div class="answer-counter counter-item">
          <span class="answer-count"><?php print $fields['comment_count']->raw; ?></span>
          <span class="answers"><?php print $fields['comment_count']->raw > 1 ? t('Answers') : t('Answer'); ?></span>
        </div>
    </div>
    <div class="flags">
      <?php if (isset($fields['ops'])): ?>
        <?php print $fields['ops']->content; ?>
      <?php endif; ?>
      <?php if (isset($fields['ops_1'])): ?>
        <?php print $fields['ops_1']->content; ?>
      <?php endif; ?>
    </div>
  </div>
</div>
