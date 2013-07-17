<?php
?>
<div class="stbody">
	<div class="stimg stimgL avatar">
  		<?php print $fields['picture']->content; ?>
	</div>
  <div class="sttext">
    <h3 class="title"><?php print $fields['name']->content; ?></h3>
    <div class="user-blogs"><?php print $fields['nid']->label; ?>:<?php print $fields['nid']->raw; ?></div>
    <div class="btn-wrap"><?php print $fields['ops']->content; ?></div>
    <div class="privatemsg_link"><?php print $fields['privatemsg_link']->content; ?></div>
  </div>
</div>
