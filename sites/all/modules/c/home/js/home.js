(function($) {


  Drupal.behaviors.muread_home = {
    attach: function(context, settings) {


      var theWord = settings.word_info.the_word;
      console.log(theWord);


      // Record hits
    /*
      $('.goto_origin').on('click', function() {
        var nid = $(this).data('nid');
        $.post('hit', {nid:nid}, function(result) {
        });
      });
      */

    }
  };

})(jQuery);
