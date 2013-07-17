<?php
/**
 * set users level
 */
function userlevel_set($uid, $level) {
  db_merge('userlevel')->key(array('uid' => $uid))->fields(array('level' => (int)$level))->execute();
}
/**
 * get users level info
 */
function userlevel_get($uid, $default=0){
    $userlevel_conf = conflevel_list();
    $userlevel = db_select('userlevel','ul')
            ->fields('ul',array('level'))
            ->condition('uid', $uid)
            ->execute()
            ->fetchAll();
    if(!empty($userlevel)){
        $level_human = $userlevel[0]->level;
        foreach($userlevel_conf as $each){
            if($each['level_human'] == $level_human){
                return $each;
                break;
            }
        }
    }
    else{
        foreach($userlevel_conf as $each){
            return $each;
            break;
        }
    }
}
/**
 * set system level info
 */
function conflevel_set($level, $points,$name,$image) {
  db_merge('userlevel_conf')
          ->key(array('level' => $level))
          ->fields(
              array(
                 'points' => (int)$points,
                 'name'=> $name,
                 'img'=>$image,
              )    
           )
          ->execute();
}
/**
 * add system level
 */
function conflevel_add($points,$name,$image) {
  db_insert('userlevel_conf')
          ->fields(
              array(
                 'points' => (int)$points,
                 'name'=> $name,
                 'img'=>$image,
                )
           )
          ->execute();
}
/**
 * list system level
 */
function conflevel_list($start=1){
    global $base_url;
    $result = db_select('userlevel_conf','uc')
            ->fields('uc',array('points','level','name','img'))
            ->orderBy('uc.points','ASC')
            ->execute()
            ->fetchAll();
    $points_level = array();
    foreach($result as $key=>$value){
        $points_level[$value->level] = array('level_human'=>$key+$start,'points'=>$value->points,'name'=>$value->name,'img'=>"<img style='with:20px;' src='".$base_url.'/'.$value->img."'/>");
	}
    return $points_level;
}
/**
 * delete system level
 */
function conflevel_delete($level){
    db_delete('userlevel_conf')
            ->condition('level', $level)
            ->execute();
}
/**
 * get a system level
 */
function conflevel_get($level, $default=''){
    $result = db_select('userlevel_conf','uc')
            ->fields('uc',array('points','name','img'))
            ->condition('level', $level)
            ->execute()
            ->fetchAll();
    if(!empty($result)){
        return $result[0];
    }
    else{
        return $default;
    }
}
/**
 * form_submit
 */
function userpoints_to_level_add_submit($form,&$form_state){
    $level = $form_state['values']['level'];
    $points = (int)$form_state['values']['points'];
    $name = $form_state['values']['name'];
    $image = $form_state['values']['destination'];
    if($level == -1){
        conflevel_add($points,$name,$image);
    }
    else{
        conflevel_set($level,$points,$name,$image);
    }
    $form_state['redirect'] = 'admin/config/people/userlevel/lists';
}
/**
 * form_validate
 */
function userpoints_to_level_add_validate($form,&$form_state){
    $temp = $_FILES['files']['tmp_name']['image'];
    $error = $_FILES['files']['error']['image'];
    $size = $_FILES['files']['size']['image'];
    $type = $_FILES['files']['type']['image'];
    $image = $_FILES['files']['name']['image'];
    $legal_types = array(
        'image/jpeg',
        'image/png',
        'image/x-icon',
        'image/bmp',
        'image/gif',
    );
    if($error != 0 || in_array($type,$legal_types) === false || $size>1024*1024){
        form_set_error('image', t('upload file occurs error!'));
    }
    else{
        $destination = drupal_get_path('module', 'userlevel').'/images/'.md5($image.time()).'.jpg';
        move_uploaded_file($temp, $destination);
        $form_state['values']['destination'] = $destination;
    }
}
/**
 * add level form
 */
function userpoints_to_level_add($form,&$form_state,$level=-1){
    $level = (int)$level;
    $levelconf = conflevel_get($level);
    $form['level'] = array(
        '#type'=>'hidden',
        '#default_value'=>$level,
    );
    $form['points'] = array(
        '#type'=>'textfield',
        '#title' => t('need  points'),
        '#default_value'=>isset($levelconf->points)?$levelconf->points:'',
        '#description'=>t('type needed-points ,have to bigger than zero'),
        '#required'=>true,
        '#element_validate' => array('element_validate_integer'), 
    );
    $form['name'] = array(
        '#type'=>'textfield',
        '#title' => t('level name'),
        '#default_value'=>isset($levelconf->name)?$levelconf->name:'',
        '#description'=>t('please type level name'),
        '#required'=>true,
    );
    $form['image'] = array(
        '#type'=>'file',
        '#description'=>t('please upload level-image,size of image must within 1M'),
        '#title' => t('level image'),
    );
    $form['submit'] = array(
        '#type'=>'submit',
        '#value' => t('submit'),
    );
    global $base_url;
    $form['cancel'] = array(
     '#type' => 'button',
     '#value' => t('Cancel'),
     '#weight' => 20,
     '#attributes' => array('onClick' => 'location.replace("'. $base_url.'/admin/config/people/userlevel/lists' .'"); return false;'),
    );
    return $form;
}
/**
 * delete level form submit
 */
function userpoints_to_level_delete_submit($form,&$form_state){
    $level = $form_state['values']['level'];
    conflevel_delete($level);
    $form_state['redirect'] = 'admin/config/people/userlevel/lists';
}
/**
 * delete level form
 */
function userpoints_to_level_delete($form,&$form_state,$level=-1){
    $level = (int)$level;
    $form['level'] = array(
        '#type'=>'hidden',
        '#default_value'=>$level,
    );
    $form['description'] = array(
      '#type' => 'item',
      '#title' => t('are you sure delete this level?'), 
    );
    $form['submit'] = array(
        '#type'=>'submit',
        '#value' => t('delete'),
    );
    return $form;
}
/**
 * list users level
 */
function userlevel_lists(){
    $rows = conflevel_list();
    $variables['header'] = array('level_human'=>t('level'),'points'=>t('need points'),'name'=>t('name'),'img'=>t('image'),'op'=>t('operation'));
    foreach($rows as $key=>&$each){
        $each['op'] = l(t('delete'),'admin/config/people/userlevel/delete/'.$key).'   '.l(t('edit'),'admin/config/people/userlevel/edit/'.$key);
    }
    $variables['rows'] = $rows;
    $variables['attributes'] = array();
    $variables['caption'] = '';
    $variables['colgroups'] = array();
    $variables['sticky'] = '';
    $variables['empty'] = '';
    $table = theme_table($variables);
    return $table;
}
/**
 * return userlevel html 
 */
function theme_userlevel($variables){
    return '<div class="userlevel-content">'.$variables['img'].'</div>';
}
/**
 * block content
 */
function userlevel_block_content($uid=-1){
    $uid = (int)$uid;
    if($uid==-1){
		if(user_is_logged_in()){
			global $user;
			$uid = $user->uid;
		}
		else{
			return t('please login!and see your level!');
		}
    }
    $userlevel = userlevel_get($uid);
    $ret = theme('userlevel',$userlevel);
    return $ret;
}

function myprofile_block_content($uid=-1){
    $uid = (int)$uid;
    if($uid==-1){
        if(user_is_logged_in()){
                global $user;
                $uid = $user->uid;
        }
        else{
                return t('please login!and see your profile!');
        }
    }
    $query = db_select('users','u');
    $query->fields('u', array('uid','picture','name','mail','created'));
    $query->fields('ut', array('points'));
    $query->fields('fc', array('count'));
    $query->fields('ul', array('level'));
    $query->fields('ub', array('userbadge'));
    $query->leftJoin('flag_counts','fc',"u.uid = fc.content_id AND fc.fid = 3");
    $query->leftJoin('userpoints_total','ut','u.uid=ut.uid');
    $query->leftJoin('userlevel','ul','u.uid=ul.uid');
    $query->leftJoin('userbadge','ub','u.uid=ub.uid');
    $query->condition('u.uid', $uid);
    $query->condition('u.status', 0,'<>');
    $query->orderBy('u.created', 'DESC');
    $query->range(0,1);;
    $variables = $query->execute()
            ->fetchAssoc();

    $account = user_load($variables['uid']);
    $variables['user_picture'] = theme('user_picture', array('account' => $account));
    if(!empty($variables['userbadge'])){
        $variables['userbadge'] = unserialize($variables['userbadge']);
    }
    else{
        $variables['userbadge'] = array();
    }
    $i = 0;
    $variables['userbadges'] = array();
    foreach($variables['userbadge'] as $each){
        $badge_conf = userbadge_conf($each);
        if(!empty($badge_conf)){
            $variables['userbadges'][] = $badge_conf;
            $i++;
            if($i == 5){
                break;
            }
        }
    }
    $care_str = $variables['count'].t(" people caring you!");
    if(empty($variables['count'])){
            $care_str = t('Share! Let others care you');
    }
    $variables['care_str'] = $care_str;
    
    $points_str = $variables['points'];
    if(empty($variables['points'])){
         $points_str = t('you have no coins.');
    }
    $variables['points_str'] = $points_str;
    $variables['username'] = format_username($account);
    $variables['userlevel'] = userlevel_block_content();

    $ret = theme('myprofile',$variables);
    return $ret;
}

function interest_people_block_content(){
    if(function_exists('get_interest_people_num')){
        $num = (int)get_interest_people_num();
    }
    else{
        $num = 10;
    }
    global $user;
    $where = '';
    if(isset($user->uid) && $user->uid>0){
        $uid = $user->uid;
        $where = " AND users.uid <> $uid";
    }
    $sql = "
        SELECT users.picture AS users_picture, users.uid AS uid, users.name AS users_name, users.mail AS users_mail, flag_content.content_id AS flag_content_content_id, RAND() AS random_field
        FROM 
        {users} users
        LEFT JOIN {flag_content} flag_content_users ON users.uid = flag_content_users.content_id AND flag_content_users.fid = '3'
        LEFT JOIN {flag_content} flag_content ON users.uid = flag_content.content_id AND (flag_content.fid = '3' AND flag_content.uid = '1' AND flag_content.sid = '0')
        WHERE (( (users.status <> '0' $where) ))
        ORDER BY random_field ASC
        LIMIT $num OFFSET 0
    ";
    $query = db_query($sql);
    $result = $query->fetchAll();
    return theme('interest_people',$result);
}















