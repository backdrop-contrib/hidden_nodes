(function ($) {
  // define function for hidden_nodes operation
  Backdrop.outline_designer_ops.hidden_nodes = function() {
    $(".od_submit_button").val('Submit');
    // set default state based on whats loaded
    if ($("#node-" + Backdrop.settings.outline_designer.activeNid +"-icon").parent().parent().hasClass('node_is_hidden')) {
      $('#od_hidden_nodes_status').attr('checked','checked');
    }
    else {
      $('#od_hidden_nodes_status').removeAttr('checked');
    }
    // function call
    Backdrop.outline_designer.render_popup(true);
  };
  // submit handler
  Backdrop.outline_designer_ops.hidden_nodes_submit = function() {
    var multiple = $('#od_hidden_nodes_multiple:checked').length;
    var hide_status = $('#od_hidden_nodes_status:checked').length;
    // update database
    Backdrop.outline_designer.ajax_call('book', 'hidden_nodes', Backdrop.settings.outline_designer.activeNid, multiple, hide_status, null);
  };
  // reset handler
  Backdrop.outline_designer_ops.hidden_nodes_reset = function() {
    $("#od_hidden_nodes_multiple").attr("checked", true);
  };
})(jQuery);