<?php

?>
<div class="comments-group">
  <div class="comment stbody">
    <div class="stimg stimgL avatar"><?php print $fields['sender_pic']->content; ?></div>
    <!-- end user face -->
    <div class="sttext comment-detail">
      <div class="comment-info"><?php print $fields['user_contextual']->content; ?></div>
      <div class="comment-content">
        <?php print $fields['message']->content; ?>
      </div>
      <!-- end comment content -->
      <div class="comment-footer clearfix">
        <div class="comment-from fl">
          <?php print $fields['created']->content; ?>
        </div>
        <ul class="clearfix unstyled comment-handle fr">
          <li><?php print $fields['edit']->content; ?></li>
          <li><?php print $fields['delete']->content; ?></li>
          <li><?php print $fields['repost']->content; ?></li>
          <li><i class="icon icon-like"></i><?php print $fields['ops']->content; ?></li>
          <li><?php print $fields['ops_1']->content; ?></li>
        </ul>
        <div class="commtent-repeat fr">
          <?php print $fields['comment-box']->content; ?>
        </div>
      </div>
      <!-- end content footer -->

    </div>
    <!-- end comment detail -->
  </div>
</div>
