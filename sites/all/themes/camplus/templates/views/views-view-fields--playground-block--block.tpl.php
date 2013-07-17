<div class="stbody">
  <div class="stimg stimgR"><?php print $fields['picture']->content; ?></div>
  <div class="sttext">
    <h3 class="title"><?php print $fields['name']->raw; ?></h3>
    <div class="user-atten clearfix">
      <div class="user-points">
        <i class="points-num"><?php print $fields['points']->raw; ?></i>
      </div>
    </div>
    <div class="user-level"><?php global $user; $userlevel = userlevel_get($user->uid); print $userlevel['img']; ?></div>
  </div>
</div>
<!-- end user profile content -->


<div class="badgebox">
  <ul class="unstyled clearfix">
    <li><img src="http://www.w3cplus.com/sites/default/files/styles/user_picture/public/pictures/picture-1-1347153884.jpg" alt="" width="24" height="24"></li>
    <li><img src="http://www.w3cplus.com/sites/default/files/styles/user_picture/public/pictures/picture-1-1347153884.jpg" alt="" width="24" height="24"></li>
    <li><img src="http://www.w3cplus.com/sites/default/files/styles/user_picture/public/pictures/picture-1-1347153884.jpg" alt="" width="24" height="24"></li>
    <li><img src="http://www.w3cplus.com/sites/default/files/styles/user_picture/public/pictures/picture-1-1347153884.jpg" alt="" width="24" height="24"></li>
    <li><img src="http://www.w3cplus.com/sites/default/files/styles/user_picture/public/pictures/picture-1-1347153884.jpg" alt="" width="24" height="24"></li>
  </ul>
</div>
<!-- end badgebox content -->

<ul class="user-nums unstyled clearfix">
  <li><?php print $fields['count']->content; ?></li>
</ul>
