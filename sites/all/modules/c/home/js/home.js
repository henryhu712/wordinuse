(function($) {


  Drupal.behaviors.muread_home = {
    attach: function(context, settings) {


      var theWord = settings.word_info.the_word;
      console.log(theWord);

      $('.keyboard-wrap .letter').on('click', function(e) {
        var letter = $(this).data('letter');
        console.log(letter);
      })

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
