<ul class="secondary-menu unstyled clearfix fl">
  <li><a href="<?php print url('user'); ?>"><i class="icon ir icon-account">用户</i></a></li>
  <li><a href="<?php print url('messages'); ?>"><i class="icon ir icon-msg">信息</i></a><i class="msg-num"><?php print privatemsg_unread_count(); ?></i></li>
  <li><a href="<?php print url('user/logout'); ?>"><i class="icon ir icon-logout">退出</i></a></li>
</ul>


