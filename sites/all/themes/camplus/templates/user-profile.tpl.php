<?php

/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 *
 * @ingroup themeable
 */
?>
<div class="profile-regions clearfix">
  <div class="profile-info fl">
    <div class="stbody">
      <div class="stimg stimgL avatar">
        <?php print render($user_profile['user_picture']); ?>
      </div>
      <div class="sttext">
        <?php foreach($user_profile['profile_profile']['view']['profile2'] as $u_p): ?>
          <div class="author-info clearfix">
            <div class="author-info_item">
              <?php print render($u_p['field_name']); ?>
            </div>
            <div class="author-info_item">
              <?php print render($u_p['field_gender']); ?>
            </div>
            <div class="author-info_item">
              <?php print render($u_p['field_birthday']); ?>
            </div>
          </div>
        <?php endforeach; ?>
        <div class="profile-level clearfix">
          <div class="profile-userlevel-content">
            <?php print userlevel_block_content(arg(1)); ?>
          </div>
          <div class="profile-userlevel-points user-points"><span class="field-content">
            <?php print userpoints_get_current_points(arg(1), 'all'); ?>
          </span></div>
        </div>
      </div>
    </div>
    <div class="profile-content">
      <?php print render($user_profile['profile_profile']['view']['profile2'][1]['field_about_me']); ?>
    </div>
    <?php print userbadge_lists(arg(1),'small'); ?>
    <div class="profile-send-msg">
      <a href="<?php print $user_profile['privatemsg_send_new_message']['#href']; ?>"><i class="icon icon-msg"></i><?php print $user_profile['privatemsg_send_new_message']['#title']; ?></a><span class="msg-num">1</span>
    </div>
  </div>
</div>
