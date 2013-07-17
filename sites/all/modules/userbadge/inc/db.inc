<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

function get_user_badge($uid){
    $userbadge = db_select('userbadge','u')
            ->fields('u', array('uid','userbadge'))
            ->condition('uid', $uid)
            ->execute()
            ->fetchAssoc();
   if(isset($userbadge['userbadge'])){
       $userbadge['userbadge'] = unserialize($userbadge['userbadge']);
       return $userbadge['userbadge'];
   }
   else{
       return array();
   }
}
function set_user_badge($uid,$badge){
    db_merge('userbadge')->key(array('uid' => $uid))->fields(array('userbadge' => serialize($badge)))->execute();
}
function get_statuses_num($uid,$num){
    $query = db_select('statuses','s');
    $query->addExpression('COUNT(`s`.`sender`)', 'num');
    $query->condition('s.sender', $uid)
          ->having('num >= :num', array(':num' => $num))
          ->where('`s`.`sender`=`s`.`recipient`');
    $num = $query->execute()
                 ->fetchAssoc();
    if(isset($num['num'])){
        return true;
    }
    else{
        return false;
    }
}
function get_statuses_touser_num($uid,$num){
    $query = db_select('statuses','s');
    $query->addExpression('COUNT(`s`.`sender`)', 'num');
    $num = $query->condition('s.sender', $uid)
        ->having('num >= :num', array(':num' => $num))
      //  ->where('`s`.`sender`<>`s`.`recipient`')
        ->condition('s.recipient', $uid,'<>')
        ->execute()
        ->fetchAssoc();
    if(isset($num['num'])){
        return true;
    }
    else{
        return false;
    }
}
function get_statuses_comment_touser_num($uid,$num){
    $query = db_select('fbss_comments','fc');
    $query->addExpression('COUNT(`fc`.`cid`)', 'num');
    $num = $query->condition('fc.uid', $uid)
        ->having('num >= :num', array(':num' => $num))
        ->groupBy('fc.sid')
        ->orderBy('num','DESC')
        ->execute()
        ->fetchAssoc();
    if(isset($num['num'])){
        return true;
    }
    else{
        return false;
    }
}
function get_statuses_like_num($uid,$num){
    $query = db_select('flag_content','fc');
    $query->addExpression('COUNT(`fc`.`uid`)', 'num');
    $num = $query->condition('fc.content_type', 'statuses')
            ->having('num >= :num', array(':num' => $num))
            ->condition('fc.fid', 9)
            ->condition('fc.uid', $uid)
            ->groupBy('fc.uid')
            ->execute()
            ->fetchAssoc();
    if(isset($num['num'])){
        return true;
    }
    else{
        return false;
    }
}
function get_statuses_liked_num($uid,$num){
    $query = db_select('flag_counts','fc');
    $query->fields('fc',array('count'));
    $query->join('statuses', 's','fc.content_id = s.sid');
    $query->condition('s.sender',$uid);
    $query->condition('fc.content_type', 'statuses');
    $query->condition('fc.fid', 9);
    $query->condition('fc.count', $num,'>=');
    $query->orderBy('fc.count', 'DESC');
    $query->range(0, 1);
    $num = $query->execute()
        ->fetchAssoc();
    if(isset($num['count'])){
        return true;
    }
    else{
        return false;
    }
}
function get_statuses_commented_num($uid,$num){
    $query = db_select('fbss_comments','fc');
    $query->fields('fc',array('cid'));
    $query->join('statuses', 's','fc.sid = s.sid');
    $query->condition('s.sender',$uid);
    $query->condition('fc.uid', $uid);
    $num = $query->execute()
        ->rowCount();
    return $num;
}



////////////////////////////////////////
/////blog
////////////////////////////////////////
function get_blog_num($uid,$num){
    $query = db_select('node','n');
    $query->addExpression('COUNT(`n`.`nid`)', 'num');
    $num = $query->condition('n.type', 'blog')
            ->having('num >= :num', array(':num' => $num))
            ->condition('n.uid', $uid)
            ->execute()
            ->fetchAssoc();
    if(isset($num['num'])){
        return true;
    }
    else{
        return false;
    }
}
function get_comment_blog_num($uid,$num){
    $query = db_select('comment','c');
    $query->fields('c',array('`cid`'));
    $query->addExpression('COUNT(`c`.`cid`)', 'num');
    $query->fields('c',array('`nid`'));
    $query->join('node', 'n','c.nid = n.nid');
    $query->condition('c.uid',$uid);
    $query->having('num >= :num', array(':num' => $num));
    $query->condition('n.type', 'blog');
    $query->groupBy('c.nid');
    $query->orderBy('num', 'DESC');
    $query->range(0, 1);
    $num = $query->execute()
        ->fetchAssoc();
    if(isset($num['num'])){
        return true;
    }
    else{
        return false;
    }
}
function get_comment_blog_using_num($uid,$num,$total){
    $query = db_select('comment','c');
    $query->addExpression('COUNT(`c`.`cid`)', 'num');
    $query->addExpression('SUM(`vv`.`value`)', 'total');
    $query->join('node', 'n','c.nid = n.nid');
    $query->join('votingapi_vote','vv','c.cid = vv.entity_id');
    $query->having('total >= :total',array(':total'=>$total));
    $query->condition('n.type','blog');
    $query->condition('c.uid',$uid);
    $query->condition('vv.value',0,'>');
    $query->groupBy('c.cid');
    $query->orderBy('num', 'DESC');
    $n = $query->execute()
        ->rowCount();
    if($n > $num){
        return true;
    }
    else{
        return false;
    }
}

function get_blog_commented_num($uid,$num){
    $query = db_select('comment','c');
    $query->addExpression('COUNT(`c`.`cid`)', 'num');
    $query->fields('c',array('nid'));
    $query->join('node', 'n','c.nid = n.nid');
    $query->condition('n.uid',$uid);
    $query->condition('n.type','blog');
    $query->having('num >= :num', array(':num' => $num));
    $query->groupBy('n.nid');
    $query->orderBy('num','DESC');
    $num = $query->execute()
        ->fetchAssoc();
    if(isset($num['num'])){
        return true;
    }
    else{
        return false;
    }
}

function get_blogs_commented_num($uid,$num,$reply){
    $query = db_select('comment','c');
    $query->addExpression('COUNT(`c`.`cid`)', 'reply');
    $query->fields('c',array('nid'));
    $query->join('node', 'n','c.nid = n.nid');
    $query->condition('n.uid',$uid);
    $query->condition('n.type','blog');
    $query->having('reply >= :reply', array(':reply' => $reply));
    $query->groupBy('n.nid');
    $n = $query->execute()
        ->rowCount();
    if($n >= $num){
        return true;
    }
    else{
        return false;
    }
}



/////////////////////////////
function get_knowledge_terms_best_num($uid,$num,$total){
    $query = db_select('comment','c');
    $query->addExpression('COUNT(`fdfba`.`field_best_answer_value`)', 'num');
    $query->join('node', 'n','c.nid = n.nid');
    $query->join('field_data_field_best_answer', 'fdfba','fdfba.entity_id = n.nid');
    $query->join('field_data_field_subject', 'fdfs','fdfs.entity_id = n.nid');
    $query->having('num >= :num',array(':num'=>$num));
    $query->where('c.cid = fdfba.field_best_answer_value');
    $query->condition('n.type','question');
    $query->condition('c.uid',$uid);
    $query->groupBy('fdfs.field_subject_tid');
    $query->orderBy('num', 'DESC');
    $t = $query->execute()
        ->rowCount();
    if($t >= $total){
        return true;
    }
    else{
        return false;
    }
}


function get_knowledge_using_num($uid,$num){
    $query = db_select('comment','c');
    $query->addExpression('SUM(`vv`.`value`)', 'num');
    $query->join('node', 'n','c.nid = n.nid');
    $query->join('votingapi_vote','vv','c.cid = vv.entity_id');
    $query->having('num >= :num',array(':num'=>$num));
    $query->condition('n.type','question');
    $query->condition('c.uid',$uid);
    $query->condition('vv.value',0,'>');
    $query->groupBy('c.cid');
    $query->orderBy('num', 'DESC');
    $n = $query->execute()
        ->rowCount();
    if($n >= 1){
        return true;
    }
    else{
        return false;
    }
}

function get_knowledge_commented_num($uid,$num){
    $query = db_select('comment','c');
    $query->addExpression('COUNT(`c`.`cid`)', 'num');
    $query->fields('c',array('nid'));
    $query->join('node', 'n','c.nid = n.nid');
    $query->condition('n.uid',$uid);
    $query->condition('n.type','question');
    $query->having('num >= :num', array(':num' => $num));
    $query->groupBy('n.nid');
    $query->orderBy('num','DESC');
    $num = $query->execute()
        ->fetchAssoc();
    if(isset($num['num'])){
        return true;
    }
    else{
        return false;
    }
}
function get_knowledge_best_num($uid,$num){
    $query = db_select('comment','c');
    $query->addExpression('COUNT(`fdfba`.`field_best_answer_value`)', 'num');
    $query->join('node', 'n','c.nid = n.nid');
    $query->join('field_data_field_best_answer', 'fdfba','fdfba.entity_id = n.nid');
    $query->having('num >= :num',array(':num'=>$num));
    $query->where('c.cid = fdfba.field_best_answer_value');
    $query->condition('n.type','question');
    $query->condition('c.uid',$uid);
    $query->orderBy('num', 'DESC');
    $n = $query->execute()
        ->rowCount();
    if($n >= 1){
        return true;
    }
    else{
        return false;
    }
}
function get_knowledge_publish_comment_num($uid,$tid,$num,$total){
    $query = db_select('node', 'n');
    $query->addExpression('COUNT(`n`.`nid`)', 'num');
    $query->join('field_data_field_subject','fdfs','n.nid=fdfs.entity_id');
    $query->condition('n.uid',$uid);
    $query->having('num >= :num', array(':num' => $num));
    $query->condition('fdfs.field_subject_tid',$tid,'IN');
    $num = $query->execute()
            ->fetchAssoc();
    if(isset($num['num'])){
        $query = db_select('comment', 'c');
        $query->addExpression('COUNT(`c`.`cid`)', 'total');
        $query->join('node','n','n.nid=c.nid');
        $query->join('field_data_field_subject','fdfs','n.nid=fdfs.entity_id');
        $query->condition('c.uid',$uid);
        $query->having('total >= :total', array(':total' => $total));
        $query->condition('fdfs.field_subject_tid',$tid,'IN');
        $total = $query->execute()
                ->fetchAssoc();
        if(isset($total['total'])){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

///////////////////////////
function get_follow_num($uid,$num){
    $query = db_select('flag_content','fc');
    $query->addExpression('COUNT(`fc`.`fcid`)', 'num');
    $query->condition('fc.content_type', 'user');
    $query->condition('fc.fid', 3);
    $query->condition('fc.uid', $uid);
    $query->having('num >= :num', array(":num"=>$num));
    $query->orderBy('num', 'DESC');
    $query->range(0, 1);
    $num = $query->execute()
        ->fetchAssoc();
    if(isset($num['count'])){
        return true;
    }
    else{
        return false;
    }
}
function get_followed_num($uid,$num){
    $query = db_select('flag_counts','fc');
    $query->fields('fc',array('count'));
    $query->condition('fc.content_type', 'user');
    $query->condition('fc.fid', 3);
    $query->condition('fc.content_id', $uid);
    $query->orderBy('fc.count', 'DESC');
    $query->range(0, 1);
    $num = $query->execute()
        ->fetchAssoc();
    if(isset($num['count'])){
        return true;
    }
    else{
        return false;
    }
}
?>
